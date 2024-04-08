/*
 * Search Algorithm
 * 
 *  Verificar se um elemento está presente em um array
 *  
 *  Temos de percorrer o array e comparar o elemento que queremos encontrar com cada elemento do array
 */

int search(int values[], int n, int value) {
    int i=0;
    
    for(i=0; i<n; i++){
        if(values[i] == value){
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int values[20] = {70, 25, 34, 15, 5, 60, 3, 55};
    int i = 0;
    
    if(search(values, 20, 60)){
        printf("O valor 60 está presente no array\n");
    } else {
        printf("O valor 60 não está presente no array\n");
    }
    
    return 0;
    
}