#include <stdio.h>
#include <stdbool.h>
/* 
1 = forbici
2 = carta
3 = sasso
4 = lucertola
5 = Spock
 */

int main(){
    int Sheldon, Leonard;

    scanf("%d%d", &Sheldon, &Leonard);

    const int forbici = 1;
    const int carta = 2;
    const int sasso = 3;
    const int lucertola = 4;
    const int spock = 5;
    int vincita = 0;
    

    if((Sheldon >= 1 && Sheldon <= 5) && (Leonard >= 1 && Leonard <= 5)){
            if(Sheldon == Leonard){ 
                vincita = 3;
            }
        
            if((Sheldon == forbici && Leonard == carta ) || (Sheldon == forbici && Leonard == lucertola )){
                
                vincita = 1;
            } 
            
            if((Sheldon == carta && Leonard == sasso ) || (Sheldon == carta && Leonard == spock )){
                
                vincita = 1;
            } 
            
            if((Sheldon == sasso && Leonard == forbici ) || (Sheldon == sasso && Leonard == lucertola )){
                
                vincita = 1;
            } 
            
            if((Sheldon == lucertola && Leonard == carta ) || (Sheldon == lucertola && Leonard == spock )){
               
                vincita = 1;
            } 
            
            if((Sheldon == spock && Leonard == sasso ) || (Sheldon == spock && Leonard == forbici )){
                vincita = 1;
            } 

            if(vincita == 1){
                printf("Sheldon");
            }
            else if (vincita == 0){
                printf("Leonard");
            }
            else if(vincita == 3){
                printf("Pareggio");
            }
        
        
    }
    else{
        printf("Non valido");
    }

}