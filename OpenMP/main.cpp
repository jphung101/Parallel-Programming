#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int count = stoi(argv[1]);
    
    #pragma omp parallel for
    for(int i = 0; i < count; i++){
        printf("%d\n", i);
    }

    return 0;
}