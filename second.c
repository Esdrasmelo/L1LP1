#include <stdio.h>
#include <math.h>

int main(void)
{
    float prim_X = 0, prim_Y = 0, seg_X = 0, seg_Y = 0;

    scanf("%f %f %f %f", &prim_X, &prim_Y, &seg_X, &seg_Y);

    do
    {
        float primContaSubtracao = seg_X - prim_X;
        float segContaSubtracao = seg_Y - prim_Y;
        float primContaPot = pow(primContaSubtracao, 2);
        float segContPot = pow(segContaSubtracao, 2);
        float contaSoma = primContaPot + segContPot;
        float contaRaizQuadrada = sqrt(contaSoma);
        printf("%f\n", contaRaizQuadrada);
        scanf("%f %f %f %f", &prim_X, &prim_Y, &seg_X, &seg_Y);
    } while (prim_X != 0 && prim_Y != 0 && seg_X != 0 && seg_Y != 0);
}