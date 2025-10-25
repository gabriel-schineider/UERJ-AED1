#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n, int m[], int k) {
	/* m = [a1, a2, ..., ak] */
	
	/*
	
	- Para saber se determinado número i é múltiplo de 
  outro número x, pode-se testar se o resto da divisão 
  de i por x resulta em 0. 
  
- Começando com s=0, pode-se varrer os números i=1,2,...,n, e 
  verificar se i deve ou não ser considerado no somatório. Se 
  sim, faz-se s = s+i. 
  Para tal verificação, varre-se cada elemento de m[1..k], 
  testando se i é múltiplo desse elemento. Se i for múltiplo 
  de algum desses elementos, i deve ser considerado no somatório.

	
	*/
	
	/* insert your code here */
	long long int s=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<k; j++)
		{
			if (i % m[j] == 0)
			{
				s += i;
				break;
			}
		}
	}
	return s;
}

int main() {
	int n; int k; 
	int * m;
	while (scanf("%d %d", &n, &k)>0) {
		m = (int *) malloc(sizeof(int)*n);
		for (int i=0; i<k; i++) {
			scanf("%d", &m[i]);
		}
		printf("%lld\n", CalculaSoma(n, m, k));
		free(m);
	}
}
