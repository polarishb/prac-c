#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    

    int m, n;
    int play = 1;
    int good = 1;

    srand(time(NULL));

    

//    while (play){

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    printf("X * X 지뢰 찾기 \n");
    printf("플레이하고 싶은 칸수를 입력해주세요: ");
    scanf("%d", &m);

    n = m;

    char **matrix = malloc(sizeof(char *) * m);
    char **map = malloc(sizeof(char *) * m);
    

    for ( int i = 0; i < m; i++){
        matrix[i] = malloc(sizeof(char) * n);
        map[i] = malloc(sizeof(char) * n);

        memset(matrix[i], 0, sizeof(char) * n);
        memset(map[i], '?', sizeof(char) * n);
    }

    int difficulty = 0;
    int try = 0;

    while(good == 1){
        if( difficulty < 1 || difficulty > 3 ){

        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        if( try != 0)
        printf("잘못입력했습니다.\n");
        printf("어려움:3 보통:2 쉬움:1 \n");
        printf("난이도를 선택해주세요: ");
        scanf("%d", &difficulty);

        try++;
        }
        else{
            good = 0;
            break;
        }
    }
    
    

    int mines = 0;
    int count;

    while( mines == 0){    // 지뢰 갯수 검사
        count = 0;

        for ( int i = 0; i < m; i++){  // 지뢰 생성
            for ( int j = 0; j < n; j++){
                matrix[i][j] = rand() % 10;
                if ( difficulty == 1 ){
                    if( matrix[i][j] == 1){
                        matrix[i][j] = '*';
                    }
                    else{
                        matrix[i][j] = '0';
                    }
                }
                else if ( difficulty == 2 ){
                    if( matrix[i][j] == 1 || matrix[i][j] == 2){
                        matrix[i][j] = '*';
                    }
                    else{
                        matrix[i][j] = '0';
                    }
                }
                else{
                    if( matrix[i][j] == 1 || matrix[i][j] == 2 || matrix[i][j] == 3){
                        matrix[i][j] = '*';
                    }
                    else{
                        matrix[i][j] = '0';
                    }
                }

                if ( matrix[i][j] == '*'){
                    count++;
                }

            }
        }

        if (count == m * n){
            mines = 0;
        }
        else{
            mines = count;
        }
    }

    for ( int i = 0; i < m; i++){               // 지뢰 주변 값 +1
        for ( int j = 0; j < n; j++){
            if (matrix[i][j] == '*'){
                for ( int a = i - 1; a <= i + 1; a++){
                    for (int b = j - 1; b <= j + 1; b++){
                        if ( a >= 0 && b >= 0 && a < m && b < n){
                            if ( matrix[a][b] != '*')
                            matrix[a][b]++;
                        }
                    }
                }
            }   
        }   
    }   

//    for ( int i = 0; i < m; i++){        //디버깅용 매핑확인 
//        for ( int j = 0; j < n; j++){
//            printf("%c", matrix[i][j]);
//        }
//        printf("\n");
//    }

    int ArrX, ArrY;
    int life = 1;
    try = 0;    

    while(life) {

        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        printf(" ㅁ ");                           // 격자  
        for ( int i = 0; i < n; i++){
            printf("%02d ", i + 1);
        }
        printf("\n");

        printf(" ㅁ┌");
        for (int i = 0; i < n; i++){
            printf("───");
        }
        printf("\n");


        for ( int i = 0; i < m; i++){       
            printf("%02d │", i + 1);
              for ( int j = 0; j < n; j++){
                if (map[i][j] == '?' || map[i][j] == '*'){
                    printf("%c%c ", map[i][j], map[i][j]);
                }
                else{
                    printf("0%c ", map[i][j]);
                }
                
            }
            printf("\n");
        }
        printf("\n");

        while(try == 0){
            printf("예) 2 5, 3 9, (x, y) \n");
            printf("지뢰를 표시하려면 (1, 0) 을 입력하세요\n");

            try++;
        }

        printf("탐색할 좌표를 입력하세요: ");
        scanf("%d %d", &ArrX, &ArrY);
        if( ArrX == 1 && ArrY == 0){                // 지뢰 표시
            printf("지뢰를 표시해주세요: ");
            scanf("%d %d", &ArrX, &ArrY);

            if ( ArrX <= 0 || ArrY <= 0 || ArrX > m || ArrY > n){
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif

                printf(" ㅁ ");                           // 격자  
                for ( int i = 0; i < n; i++){
                    printf("%02d ", i + 1);
                }
                printf("\n");

                printf(" ㅁ┌");
                for (int i = 0; i < n; i++){
                    printf("───");
                }
                printf("\n");


                for ( int i = 0; i < m; i++){       
                    printf("%02d │", i + 1);
                      for ( int j = 0; j < n; j++){
                        if (map[i][j] == '?' || map[i][j] == '*'){
                            printf("%c%c ", map[i][j], map[i][j]);
                        }
                        else{
                            printf("0%c ", map[i][j]);
                        }

                    }
                    printf("\n");
                }
                printf("\n");

                printf("올바르지 않은 수입니다. \n");

                printf("지뢰를 표시해주세요: ");
                scanf("%d %d", &ArrX, &ArrY);
            }
            else if(matrix[ArrY-1][ArrX-1] != '*' && map[ArrY-1][ArrX-1] == matrix[ArrY-1][ArrX-1]){
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif

                printf(" ㅁ ");                           // 격자  
                for ( int i = 0; i < n; i++){
                    printf("%02d ", i + 1);
                }
                printf("\n");

                printf(" ㅁ┌");
                for (int i = 0; i < n; i++){
                    printf("───");
                }
                printf("\n");


                for ( int i = 0; i < m; i++){       
                    printf("%02d │", i + 1);
                      for ( int j = 0; j < n; j++){
                        if (map[i][j] == '?' || map[i][j] == '*'){
                            printf("%c%c ", map[i][j], map[i][j]);
                        }
                        else{
                            printf("0%c ", map[i][j]);
                        }

                    }
                    printf("\n");
                }
                printf("\n");

                printf("올바르지 않은 수입니다. \n");

                printf("지뢰를 표시해주세요: ");
                scanf("%d %d", &ArrX, &ArrY);
            }
            else if(map[ArrY-1][ArrX-1] == '*'){
                map[ArrY-1][ArrX-1] = '?';
            }
            else{
                map[ArrY-1][ArrX-1] = '*';
            }
        }
        else if ( ArrX <= 0 || ArrY <= 0 || ArrX > m || ArrY > n){  // 힌트 오픈

            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            printf(" ㅁ ");                           // 격자  
            for ( int i = 0; i < n; i++){
                printf("%02d ", i + 1);
            }
            printf("\n");

            printf(" ㅁ┌");
            for (int i = 0; i < n; i++){
                printf("───");
            }
            printf("\n");


            for ( int i = 0; i < m; i++){       
                printf("%02d │", i + 1);
                  for ( int j = 0; j < n; j++){
                    if (map[i][j] == '?' || map[i][j] == '*'){
                        printf("%c%c ", map[i][j], map[i][j]);
                    }
                    else{
                        printf("0%c ", map[i][j]);
                    }

                }
                printf("\n");
            }
            printf("\n");

            printf("올바르지 않은 수입니다. \n");

            printf("찾을 곳을 입력하세요: ");
            scanf("%d %d", &ArrX, &ArrY);
        }
        else
        {
            if ( matrix[ArrY-1][ArrX-1] == '*'){   // 지뢰를 찾음

                map[ArrY-1][ArrX-1] = matrix[ArrY-1][ArrX-1];

                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif

                

                printf(" ㅁ ");                           // 격자  
                for ( int i = 0; i < n; i++){
                    printf("%02d ", i + 1);
                }
                printf("\n");
            
                printf(" ㅁ┌");
                for (int i = 0; i < n; i++)
                {
                    printf("───");
                }
                printf("\n");
                
                
                
                for ( int i = 0; i < m; i++){       
                    printf("%02d │", i + 1);
                      for ( int j = 0; j < n; j++){
                        if (map[i][j] == '?' || map[i][j] == '*'){
                            printf("%c%c ", map[i][j], map[i][j]);
                        }
                        else{
                            printf("0%c ", map[i][j]);
                        }
                        
                    }
                    printf("\n");
                  }
            
                printf("\n");

                printf("지뢰가 터졌습니다. \n");
                printf("GAME OVER \n");

                life = 0;
                break;
            }
            else if( matrix[ArrY-1][ArrX-1] == '0')    // 0을 찾음
            {
                for ( int i = ArrY - 2; i <= ArrY; i++){
                    for ( int j = ArrX - 2; j <= ArrX; j++){
                        if ( i >= 0 && j >= 0 && i < m && j < n){

                            if ( matrix[i][j] == '0'){
                                map[i][j] = matrix[i][j];

                                for (int y = i - 1; y <= i + 1; y++){
                                    for (int x = j - 1; x <= j + 1; x++){
                                        if( y >= 0 && x >= 0 && y < m && x < n){
                                            if ( matrix[y][x] != '*')
                                            map[y][x] = matrix[y][x];

                                            if( matrix[y][x] == '0'){
                                                for (int a = y -1; a <= y + 1; a++){
                                                    for (int b = x - 1; b <= x + 1; b++){
                                                        if( a >= 0 && b >= 0 && a < m && b < n){
                                                            if ( matrix[a][b] != '*')
                                                            map[a][b] = matrix[a][b];
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }    
            else    // 힌트를 찾음
            {
                map[ArrY-1][ArrX-1] = matrix[ArrY-1][ArrX-1];
            }

            

        }

        mines = 0;
        count = 0;

        for ( int i = 0; i < m; i++){   //  정답 체크
                for (int j = 0; j < n; j++){

                    if( matrix[i][j] == '*'){
                        mines++;
                    }

                    if( map[i][j] == '?' || map[i][j] == '*'){
                        count++;
                    }
                }
            }

            if ( count == mines){

                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif    

                printf(" ㅁ ");                           // 격자  
                for ( int i = 0; i < n; i++){
                    printf("%02d ", i + 1);
                }
                printf("\n");
            
                printf(" ㅁ┌");
                for (int i = 0; i < n; i++)
                {
                    printf("───");
                }
                printf("\n");
                
                for ( int i = 0; i < m; i++){       
                    printf("%02d │", i + 1);
                      for ( int j = 0; j < n; j++){
                        if (map[i][j] == '?' || map[i][j] == '*'){
                            printf("%c%c ", map[i][j], map[i][j]);
                        }
                        else{
                            printf("0%c ", map[i][j]);
                        }
                        
                    }
                    printf("\n");
                  }
            
                printf("\n");        
            
                    printf("축하합니다. \n");
                    printf("GAME CLEAR! \n");
                    printf("시도한 횟수: %d\n", try);
                    
                    life = 0;
                    break;
                }

        try++;           
    
        
    }

//    char c1;
//
//   printf("다시 플레이하겠습니까?: ");
//    scanf("%c", &c1);
//
//    if(c1 == 'y' || c1 == 'Y'){
//        play = 1;
//    }
//    else{
//        play = 0;
//    }

    for ( int i = 0; i < m; i++){  //메모리 해제
        free(matrix[i]);
        free(map[i]);
    }

    free(matrix);
    free(map);    

    
//    }
    

    

    return 0;
}