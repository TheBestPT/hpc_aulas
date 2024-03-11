#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int t_inicio = time(0);
    int t_final;
    int soma;
    #pragma omp parallel for num_threads(32)
        
        for (int k = 0; k < 4*8; k++)
        {
            int tid = omp_get_thread_num();
            int t_inicio = omp_get_wtime();
            
            printf("Hello OMP, k=%d thread: %d\n", k, tid);
            if (k % 2) {
                sleep(5);
            }else{
                sleep(2);
            }
            int t_final = omp_get_wtime();

            printf("Hello OMP, k=%d thread = %d tempo thread = %d\n", k, tid, t_final-t_inicio);
            soma += k;
        }
    printf("%s %d\n", "Soma de k = ", soma);  
    t_final = time(0);
    printf("%s %d\n", "tempo total de execução = ", (t_final - t_inicio));
    return EXIT_SUCCESS;
}    