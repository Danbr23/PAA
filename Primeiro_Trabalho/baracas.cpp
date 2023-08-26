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

        for(i=0;i<homens;i++){
            for(j=0;j<mulheres;j++){
                if(coordenadasMulheres[j][2] > coordenadasHomens[i][0]) break;
                else{
                    if(j == mulheres-1) mulheresOk=true;
                }
            }

            if(mulheresOk){
                for(j=0;j<homens;j++){
                    if(coordenadasHomens[j][0] < coordenadasHomens[i][0]) break;
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

        

            for(j=0;j<mulheres;j++){
                if((coordenadasMulheres[j][2] <= coordenadasHomens[i][0]) || (coordenadasMulheres[j][1] <= coordenadasHomens[i][3])) continue;
                coeficienteAngular = (coordenadasMulheres[j][1] - coordenadasHomens[i][3]) / (coordenadasMulheres[j][2] - coordenadasHomens[i][0]);
                coeficienteLinear = coordenadasMulheres[j][1] - (coeficienteAngular * coordenadasMulheres[j][2]);

                for(k=0;k<mulheres;k++){
                    yDiagonal = (coeficienteAngular * coordenadasMulheres[k][2]) + coeficienteLinear;
//                    cout << "yDiagonal: "<< yDiagonal << " e y verdadeiro: " << coordenadasMulheres[k][1] << endl;
                    if(coordenadasMulheres[k][1] < round(yDiagonal)) break;
                    else{
                        if(k == mulheres-1) mulheresOk = true;
                    }
                }

                if(mulheresOk){
                    for(k=0;k<homens;k++){
                        yDiagonal = (coeficienteAngular * coordenadasHomens[k][0]) + coeficienteLinear;
//                        cout << "yDiagonal: "<< round(yDiagonal) << " e y verdadeiro: " << coordenadasHomens[k][3] << endl;
                        if(coordenadasHomens[k][3] > round(yDiagonal)) break;
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

/*
    1 - 

*/

/*

PONTO SUPERIOR ESQUERDO
3 3
10 10 20 20
30 30 40 40
50 50 60 60
10 40 20 50
30 60 40 70
50 80 60 90

PONTO INFERIOR DIREITO
3 3
10 40 20 50
50 80 60 90
30 60 40 70
30 30 40 40
50 50 60 60
10 10 20 20

PONTO INFERIOR ESQUERDO
3 3
10 80 20 90
30 60 40 70
50 40 60 50
10 50 20 60
30 30 40 40
50 10 60 20

PONTO SUPERIOR DIREITO
3 3
10 50 20 60
30 30 40 40
50 10 60 20
10 80 20 90
30 60 40 70
50 40 60 50

RETA VERTICAL ESQUERDA
3 3
30 10 40 20
30 30 40 40
30 50 40 60
10 10 20 20
10 30 20 40
10 50 20 60

RETA VERTICAL DIREITA
3 3
10 10 20 20
10 30 20 40
10 50 20 60
30 10 40 20
30 30 40 40
30 50 40 60

RETA HORIZONTAL DE CIMA
3 3
30 30 40 40
50 30 60 40
70 30 80 40
30 10 40 20
50 10 60 20
70 10 80 20

RETA HORIZONTAL DE BAIXO
3 3
30 10 40 20
50 10 60 20
70 10 80 20
30 30 40 40
50 30 60 40
70 30 80 40

teste git 234
PONTO INFERIOR ESQUERDO TANGENTES
3 3
10 80 20 90
30 60 40 70
50 40 60 50
10 60 20 70
30 40 40 50
50 20 60 30

PONTO SUPERIOR DIREITO TANGENTES
3 3
10 60 20 70
30 40 40 50
50 20 60 30
10 80 20 90
30 60 40 70
50 40 60 50

PONTO INFERIOR DIREITO TANGENTES
3 3
70 50 80 60
80 70 90 80
90 90 100 100
80 40 90 50
90 60 100 70
100 80 110 90

PONTO SUPERIOR ESQUERDO 
3 3
80 40 90 50
90 60 100 70
100 80 110 90
70 50 80 60
80 70 90 80
90 90 100 100

*/

            /*
            omega = 0;
            acrescimo = 3.14156/90;
            // indo de 0 a 45 graus em radianos
            for(int k=0;k<45;k++){
                // verificando para todas as outras barracas
                for(j=0;j<homens;j++){
                    // ela mesma nao conta
                    if(j!=i){
                        yDiagonal = (tan(omega) * (coordenadasHomens[j][0] - coordenadasHomens[i][0])) + coordenadasHomens[i][3];
                        if(coordenadasHomens[j][3] > yDiagonal){
                             separavel = false;
                             break;
                             }else separavel = true;
                        cout << coordenadasHomens[j][3] << "::" << yDiagonal  << endl;
                    }
                }
                if(separavel){
                    k=45;
                    i=homens;
                    cout << "Deu certo ehhhh";
                }   
                omega += acrescimo;
            }
            */

            /*
            for(j=0;j<homens;j++){
                if(j != i){
                    // se estiver na esquerda
                    if(coordenadasHomens[j][0] > coordenadasHomens[i][0]){
                        //se estiver com pelo menos mais 1 no eixo y 
                        if(coordenadasHomens[j][3] > coordenadasHomens[i][3]){
                            // coeficiente Angular = (x1' - x1) / (y2' - y2)
                            coeficienteAngular = (coordenadasHomens[j][3] - coordenadasHomens[i][3]) / (coordenadasHomens[j][0] - coordenadasHomens[i][0]); 
                            //c coeficiente Linear = y2 - coeficienteAngular * x1 
                            coeficienteLinear = coordenadasHomens[i][3] - (coeficienteAngular * coordenadasHomens[i][0]);
                        }
                    


                    }
                }
            }
            */