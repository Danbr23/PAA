#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int homens, mulheres, i, j, k, contador=0; 
    float x1, y1, x2, y2, coeficienteLinear;
    double coeficienteAngular, yDiagonal;
    double omega, acrescimo;
    bool mulheresOk=false, homensOk=false, separavel = false;
    string respostas="";

    cin >> homens >> mulheres;

    float coordenadasHomens[homens][4];
    float coordenadasMulheres[mulheres][4];

    while((homens != 0)&&(mulheres != 0)){
        
        homensOk = mulheresOk = false;
        contador++;

        for(i=0; i<homens;i++){
            cin >> x1 >> y1 >> x2 >> y2;
            coordenadasHomens[i][0] = x1;
            coordenadasHomens[i][1] = y1;
            coordenadasHomens[i][2] = x2;
            coordenadasHomens[i][3] = y2;
        }

        for(i=0; i<mulheres;i++){
            cin >> x1 >> y1 >> x2 >> y2;
            coordenadasMulheres[i][0] = x1;
            coordenadasMulheres[i][1] = y1;
            coordenadasMulheres[i][2] = x2;
            coordenadasMulheres[i][3] = y2;
        }

        // TRECHO DO CODIGO PARA VERIFICAR AS RETAS VERTICAIS DO LADO ESQUERDO ESQUERDO DAS BARRCAS MASCULINAS

        for(i=0;i<homens;i++){ // h * ( 4 * (2m + 1 +2h + 2) + 4 * ( m(4mh + 8m + 4h + 2) + 9)) + 3
                               // h * (  8m + 4 + 8h + 8 + 4m(4mh + 8m + 4h + 2) + 36) + 3
                               // h * ( 4m²h + 32m² 16mh 24m + 8m + 48) + 3
                               // 4m²h² + 16mh² + 32m²h + 32mh + 48h + 3 
            for(j=0;j<mulheres;j++){ // m 
                if(coordenadasMulheres[j][2] > coordenadasHomens[i][0]) break; // 1
                else{
                    if(j == mulheres-1) mulheresOk=true;// 1 vez // 1
                }
            } // 2m + 1

            if(mulheresOk){ // 1
                for(j=0;j<homens;j++){ // h
                    if(coordenadasHomens[j][0] < coordenadasHomens[i][0]) break; // 1
                    else{
                        if(j==homens-1) homensOk=true; // 1 vez  // 1
                    } 
                }
            }// 2h + 2

            if((mulheresOk)&&(homensOk)){ // 1 vez
                respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                break;
            }
        
            mulheresOk = homensOk = false; // 1 vez

        // TRECHO DO CODIGO PARA VERIFICAR AS RETAS VERTICAIS DO LADO DIREITO DAS BARRCAS MASCULINAS

            for(j=0;j<mulheres;j++){
                if(coordenadasMulheres[j][0] < coordenadasHomens[i][0]) break;
                else{
                    if(j == mulheres-1) mulheresOk=true;
                }
            }

            if(mulheresOk){
                for(j=0;j<homens;j++){
                    if(coordenadasHomens[j][2] > coordenadasHomens[i][2]) break;
                    else{
                        if(j==homens-1) homensOk=true;
                    }
                }
            }

            if((mulheresOk)&&(homensOk)){
                respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                break;
            }
            
            mulheresOk = homensOk = false;
        
        // TRECHO DO CODIGO PARA VERIFICAR AS RETAS HORIZONTAIS DE CIMA DAS BARRACAS MASCULINAS
        
            for(j=0;j<mulheres;j++){
                if(coordenadasMulheres[j][3] > coordenadasHomens[i][1]) break;
                else{
                    if(j == mulheres-1) mulheresOk=true;
                }
            }

            if(mulheresOk){
                for(j=0;j<homens;j++){
                    if(coordenadasHomens[j][1] < coordenadasHomens[i][1]) break;
                    else{
                        if(j==homens-1) homensOk=true;
                    }
                }
            }

            if((mulheresOk)&&(homensOk)){
                respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                break;
            }
            
            mulheresOk = homensOk = false;
        
        // TRECHO DO CODIGO PARA VERIFICAR AS RETAS HORIZONTAIS DE BAIXO DAS BARRACAS MASCULINAS

            for(j=0;j<mulheres;j++){
                if(coordenadasMulheres[j][1] < coordenadasHomens[i][3]) break;
                else{
                    if(j == mulheres-1) mulheresOk=true;
                }
            }

            if(mulheresOk){
                for(j=0;j<homens;j++){
                    if(coordenadasHomens[j][3] > coordenadasHomens[i][3]) break;
                    else{
                        if(j==homens-1) homensOk=true;
                    }
                }
            }

            if((mulheresOk)&&(homensOk)){
                respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                break;
            }
            
            mulheresOk = homensOk = false;
        

        // TRECHO DO CODIGO PARA VERIFICAR A RETA DIAGONAL DO PONTO SUPERIOR ESQUERDO DAS BARRCAS MASCULINAS

            for(j=0;j<mulheres;j++){ // m
    /* 2 */     if((coordenadasMulheres[j][2] <= coordenadasHomens[i][0]) || (coordenadasMulheres[j][1] <= coordenadasHomens[i][3])) continue;
    /* 3 */     coeficienteAngular = (coordenadasMulheres[j][1] - coordenadasHomens[i][3]) / (coordenadasMulheres[j][2] - coordenadasHomens[i][0]);
    /* 2 */     coeficienteLinear = coordenadasMulheres[j][1] - (coeficienteAngular * coordenadasMulheres[j][2]);

                for(k=0;k<mulheres;k++){ // m
    /* 2 */         yDiagonal = (coeficienteAngular * coordenadasMulheres[k][2]) + coeficienteLinear;
//                    cout << "yDiagonal: "<< yDiagonal << " e y verdadeiro: " << coordenadasMulheres[k][1] << endl;
    /* 1 */           if(coordenadasMulheres[k][1] < round(yDiagonal)) break;
                    else{
    /* 1 */              if(k == mulheres-1) mulheresOk = true; // 1 ves;
                    }
                } // 4m + 1

                if(mulheresOk){ // 1 vez
                    for(k=0;k<homens;k++){ // h
                        yDiagonal = (coeficienteAngular * coordenadasHomens[k][0]) + coeficienteLinear; // 2
//                        cout << "yDiagonal: "<< round(yDiagonal) << " e y verdadeiro: " << coordenadasHomens[k][3] << endl;
                        if(coordenadasHomens[k][3] > round(yDiagonal)) break; // 1
                        else{
                            if(k == homens-1) homensOk = true; // 1
                        }
                    }
                } // 4h + 2

                if((mulheresOk)&&(homensOk)){ // 1
                    respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                    break;
                }
                mulheresOk = homensOk = false; // 1
            } 

            if((mulheresOk)&&(homensOk)){ // 1
                break;
            } //m * (4m +1) * (4h + 2) + 1 + 1 + 7 => m * (4m +1) * (4h + 2) + 9 
              // (4m² + m) * (4h + 2) + 9
              // 4m²h + 8m² + 4hm + 2m + 9
              // m(4mh + 8m + 4h + 2) + 9

        // TRECHO DO CODIGO PARA VERIFICAR A RETA DIAGONAL DO PONTO INFERIOR DIREITO DAS BARRACAS MASCULINAS

            for(j=0;j<mulheres;j++){
                if((coordenadasMulheres[j][0] <= coordenadasHomens[i][2]) || (coordenadasMulheres[j][3] <= coordenadasHomens[i][1])) continue;
                coeficienteAngular = (coordenadasHomens[i][1] - coordenadasMulheres[j][3]) / (coordenadasHomens[i][2] - coordenadasMulheres[j][0]);
                coeficienteLinear = coordenadasHomens[i][1] - (coeficienteAngular * coordenadasHomens[i][2]);

                for(k=0;k<mulheres;k++){
                    yDiagonal = (coeficienteAngular * coordenadasMulheres[k][0]) + coeficienteLinear;
//                    cout << "yDiagonal: "<< ceil(yDiagonal) << " e y verdadeiro: " << coordenadasMulheres[k][3] << endl;
                    if(coordenadasMulheres[k][3] > ceil(yDiagonal)) break;
                    else{
                        if(k == mulheres-1) mulheresOk = true;
                    }
                }

                if(mulheresOk){
                    for(k=0;k<homens;k++){
                        yDiagonal = (coeficienteAngular * coordenadasHomens[k][2]) + coeficienteLinear;
//                        cout << "yDiagonal: "<< round(yDiagonal) << " e y verdadeiro: " << coordenadasHomens[k][1] << endl;
                        if(coordenadasHomens[k][1] < round(yDiagonal)) break;
                        else{
                            if(k == homens-1) homensOk = true;
                        }
                    }
                }

                if((mulheresOk)&&(homensOk)){
                    respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                    break;
                }

                mulheresOk = homensOk = false;
            }

            if((mulheresOk)&&(homensOk)){
                break;
            }    

        // TRECHO DO CODIGO PARA VERIFICAR A RETA DIAGONAL DO PONTO INFERIOR ESQUERDO DAS BARRACAS MASCULINAS

            for(j=0;j<mulheres;j++){
                if((coordenadasMulheres[j][2] <= coordenadasHomens[i][0]) || (coordenadasMulheres[j][3] >= coordenadasHomens[i][1])) continue;
                coeficienteAngular = (coordenadasHomens[i][1] - coordenadasMulheres[j][3]) / (coordenadasHomens[i][0] - coordenadasMulheres[j][2]);
                coeficienteLinear = coordenadasHomens[i][1] - (coeficienteAngular * coordenadasHomens[i][0]);

                for(k=0;k<mulheres;k++){
                    yDiagonal = (coeficienteAngular * coordenadasMulheres[k][2]) + coeficienteLinear;
//                    cout << "yDiagonal: "<< round(yDiagonal) << " e y verdadeiro: " << coordenadasMulheres[k][3] << endl;
                    if(coordenadasMulheres[k][3] > round(yDiagonal)) break;
                    else{
                        if(k == mulheres-1) mulheresOk = true;
                    }
                }

                if(mulheresOk){
                    for(k=0;k<homens;k++){
                        yDiagonal = (coeficienteAngular * coordenadasHomens[k][0]) + coeficienteLinear;
//                        cout << "yDiagonal: "<< round(yDiagonal) << " e y verdadeiro: " << coordenadasHomens[k][1] << endl;
                        if(coordenadasHomens[k][1] < round(yDiagonal)) break;
                        else{
                            if(k == homens-1) homensOk = true;
                        }
                    }
                }

                if((mulheresOk)&&(homensOk)){
                    respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";;;
                    break;
                }

                mulheresOk = homensOk = false;
            }

            if((mulheresOk)&&(homensOk)){
                break;
            }    

        // TRECHO DO CODIGO PARA VERIFICAR A RETA DIAGONAL DO PONTO SUPERIOR DIREITO DAS BARRACAS MASCULINAS

            for(j=0;j<mulheres;j++){
                if((coordenadasMulheres[j][0] <= coordenadasHomens[i][2]) || (coordenadasMulheres[j][1] >= coordenadasHomens[i][3])) continue;
                coeficienteAngular = (coordenadasHomens[i][3] - coordenadasMulheres[j][1]) / (coordenadasHomens[i][2] - coordenadasMulheres[j][0]);
                coeficienteLinear = coordenadasHomens[i][3] - (coeficienteAngular * coordenadasHomens[i][2]);

                for(k=0;k<mulheres;k++){
                    yDiagonal = (coeficienteAngular * coordenadasMulheres[k][0]) + coeficienteLinear;
//                    cout << "yDiagonal: "<< round(yDiagonal) << " e y verdadeiro: " << coordenadasMulheres[k][1] << endl;
                    if(coordenadasMulheres[k][1] < round(yDiagonal)) break;
                    else{
                        if(k == mulheres-1) mulheresOk = true;
                    }
                }

                if(mulheresOk){
                    for(k=0;k<homens;k++){
                        yDiagonal = (coeficienteAngular * coordenadasHomens[k][2]) + coeficienteLinear;
//                        cout << "yDiagonal: "<< ceil(yDiagonal) << " e y verdadeiro: " << coordenadasHomens[k][3] << endl;
                        if(coordenadasHomens[k][3] > ceil(yDiagonal)) break;
                        else{
                            if(k == homens-1) homensOk = true;
                        }
                    }
                }

                if((mulheresOk)&&(homensOk)){
                    respostas += "\nCaso " + to_string(contador) + ": É possível separar os dois grupos!\n";
                    break;
                }
                mulheresOk = homensOk = false;
            }

            if((mulheresOk)&&(homensOk)) break;
        }

        if((!mulheresOk)&&(!homensOk)) respostas += "\nCaso " + to_string(contador) + ": Não é possível separar os dois grupos!\n";

    
        cin >> homens >> mulheres;
    }

    cout << respostas << endl;
    return 0;
}
