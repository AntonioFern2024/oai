#include <stdio.h>
#include <math.h>
#include "openair1/PHY/TOOLS/tools_defs.h"
#include "openair1/SIMULATION/TOOLS/sim.h"
#include "common/utils/utils.h"
#define SZ_PTR(Sz) {Sz},
struct {
  int size;
} const dftFtab[] = {FOREACH_DFTSZ(SZ_PTR)};

#define SZ_iPTR(Sz) {Sz},
struct {
  int size;
} const idftFtab[] = {FOREACH_IDFTSZ(SZ_iPTR)};

bool error(c16_t v16, cd_t vd, double percent)
{
  cd_t err = {abs(v16.r - vd.r), abs(v16.i - vd.i)};
  if (err.r < 10 && err.i < 10)
    return false; // ignore quantization noise
  int denomr = min(abs(v16.r), abs(vd.r));
  if (denomr && err.r / denomr > percent / 100)
    return true;
  int denomi = min(abs(v16.i), abs(vd.i));
  if (denomi && err.i / denomi > percent / 100)
    return true;
  return false;
}

void math_dft(cd_t *in, cd_t *out, int len)
{
  for (int k = 0; k < len; k++) {
    cd_t tmp = {0};
    // wrote this way to help gcc to generate SIMD
    double phi[len], sint[len], cost[len];
    for (int n = 0; n < len; n++)
      phi[n] = -2 * M_PI * ((double)k / len) * n;
    for (int n = 0; n < len; n++)
      sint[n] = sin(phi[n]);
    for (int n = 0; n < len; n++)
      cost[n] = cos(phi[n]);
    for (int n = 0; n < len; n++) {
      cd_t coeff = {.r = cost[n], .i = sint[n]};
      cd_t component = cdMul(coeff, in[n]);
      tmp.r += component.r;
      tmp.i += component.i;
    }
    out[k].r = tmp.r / sqrt(len);
    out[k].i = tmp.i / sqrt(len);
  }
}

int main(void)
{
  load_dftslib();
  c16_t *d16 = malloc16(12 * dftFtab[sizeofArray(dftFtab) - 1].size * sizeof(*d16));
  c16_t *o16 = malloc16(12 * dftFtab[sizeofArray(dftFtab) - 1].size * sizeof(*d16));
  for (int sz = 0; sz < sizeofArray(dftFtab); sz++) {
    const int n = dftFtab[sz].size;
    cd_t data[n];
    double coeffs[] = {0.1, 0.25, 0.5, 1, 1.5, 2};
    cd_t out[n];
    for (int i = 0; i < n; i++) {
      data[i].r = gaussZiggurat(0, 0); // gaussZiggurat not used paramters, to fix
      data[i].i = gaussZiggurat(0, 0);
    }
    math_dft(data, out, n);
    double evm[sizeofArray(coeffs)]={0};
    for (int coeff=0; coeff<sizeofArray(coeffs); coeff++) {
      double expand = coeffs[coeff] * SHRT_MAX / sqrt(n);

      for (int i = 0; i < n; i++) {
        d16[i].r = expand * data[i].r;
        d16[i].i = expand * data[i].i;
      }

      dft(get_dft(n), (int16_t *)d16, (int16_t *)o16, 1);
      for (int i = 0; i < n; i++) {
        cd_t error = {.r = o16[i].r / expand - out[i].r, .i = o16[i].i / expand - out[i].i};
        evm[coeff] += sqrt(squaredMod(error)) / sqrt(squaredMod(out[i]));
        /*
          if (error(o16[i], out[i], 5))
          printf("Error in dft %d at %d, (%d, %d) != %f, %f)\n", n, i, o16[i].r, o16[i].i, gslout[i].r, gslout[i].i);
        */
      }
    }
    printf("done DFT size %d (evm (%%),amplitude) = ", n);
    for (int coeff=0; coeff<sizeofArray(coeffs); coeff++)
      printf("(%.2f, %.0f) ", evm[coeff] / n *100, coeffs[coeff]* SHRT_MAX / sqrt(n) );
    printf("\n");
  }
  free(d16);
  free(o16);
  return 0;
}
