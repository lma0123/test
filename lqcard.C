int indx[4] = {1,2,3,4};//4张牌标号
void shuffle(int arr[]);//洗牌函数
void flip(char *cardarr[]);//根据名字长度把顶面的牌后置
void movetop3cards(char *cardarr[]);//把最上面3张插入牌堆中间任意处
void movetopXcards(char *cardarr[], int rd);//南北方人从顶部随机取1-3张插入中间
void flip1card(char *cardarr[], int rd);//见证奇迹的时刻，7字箴言，挪7张
void discard_top_card(char *cardarr[], int rd);//男生扔1张，女生扔2张

void lqcard()
{
  const int keyword = 7;

  string init_card[4]={"3","8","6","7"};// J\Q\K\A， 可随意换

  string card[2][4] = {"3_1","8_1","6_1","7_1","3_2","8_2","6_2","7_2"}; // J\Q\K\A， 可随意换

  char *split_card[8];

  srand((unsigned)time(NULL)); 
  
  shuffle(indx); //洗牌

  cout<<"shuffled cards: ";

  for(int j=0; j<4; j++) {//撕成两半
    cout << init_card[indx[j]-1] <<"  ";
    split_card[j] = (char*)(card[0][indx[j]-1].data());
    split_card[j+4] =(char*)(card[1][indx[j]-1].data());
  }

  cout<<endl;
  cout << "4 cards are broken into half" << endl;
  
  for(int i=0; i<8; i++)  cout << split_card[i] << "  ";
  cout << endl;

  flip(split_card); 

  for(int i=0; i<8; i++)  cout << split_card[i] << "  ";
  cout << endl;

  movetop3cards(split_card); 

  for(int i=0; i<8; i++)  cout << split_card[i] << "  ";
  cout << endl;
  
  char *hiddencard = split_card[0];
  cout << "The hidden card is: " << hiddencard << endl;

  char *newcard[7];
  for(int i=0; i<7; i++) newcard[i] = split_card[i+1];
  
  movetopXcards(newcard, rand()%3+1); 

  for(int i=0; i<7; i++) cout << newcard[i] << "  ";
  cout << endl;
  
  int gender = rand()%2+1;
  discard_top_card(newcard, gender); //男生扔1张，女生扔2张

  if(gender == 1) {
    char *newcard1[6];
    for(int i=0; i<7-gender; i++) { newcard1[i] = newcard[i]; cout << newcard1[i] << " "; }

    flip1card(newcard1,7-gender); //见证奇迹的时刻，7字箴言，挪7张
    cout << endl;
    cout << "Seven key words ... " << endl;
    for(int i=0; i<7-gender; i++) cout << newcard1[i] << "  ";
    cout << endl;

    cout << "The final card is : " << hiddencard << " + " << newcard1[2*(3-gender)] << endl; //好运留下烦恼抛开最后必然女生留下第三张牌，男生留下第五张
  }

  if(gender == 2) {
    char *newcard1[5];
    for(int i=0; i<7-gender; i++) { newcard1[i] = newcard[i]; cout << newcard1[i] << " "; }

    flip1card(newcard1,7-gender); //见证奇迹的时刻，7字箴言，挪7张
    cout << endl;
    cout << "Seven key words ... " << endl;
    for(int i=0; i<7-gender; i++) cout << newcard1[i] << "  ";
    cout << endl;

    cout << "The final card is : " << hiddencard << " + " << newcard1[2*(3-gender)] << endl; //好运留下烦恼抛开最后必然女生留下第三张牌，男生留下第五张

}
  
//cout << endl;


}

void shuffle(int arr[])
{
    for (int n = 0; n < 10; n++)
    {
      int i = rand() % 4;
      int j = rand() % 4; 

      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
}

void flip(char *cardarr[])
{
  int namelength = rand()%3+2; // 2-4
  char *temp[8];
  for(int i=0; i<8; i++) temp[i] = cardarr[i]; 

  for(int i=0; i<8-namelength; i++) cardarr[i] = temp[i+namelength];

  for(int i=0; i<namelength; i++) cardarr[8-namelength+i] = temp[i];

  cout << namelength << " cards are move back" << endl;
  
}

void movetop3cards(char *cardarr[])
{
  int gap = rand()%4+1; // 1-4，5张牌的任意间隙
  char *temp[8];
  for(int i=0; i<8; i++)  temp[i] = cardarr[i];

  for(int i=0; i<gap; i++) cardarr[i] = temp[3+i];

  for(int i=gap; i<gap+3; i++) cardarr[i] = temp[i-gap];

  for(int i=gap+3; i<8; i++) cardarr[i] = temp[i];

  cout << " Top 3 cards are inserted in the middle " << endl;
  
}

void movetopXcards(char *cardarr[], int rd)
{

  int gap = rand()%(7-rd-1)+1; // 取rd张牌后剩余牌的任意间隙
  char *temp[7];
  for(int i=0; i<7; i++)  temp[i] = cardarr[i];

  for(int i=0; i<gap; i++) cardarr[i] = temp[3+i];

  for(int i=gap; i<gap+rd; i++) cardarr[i] = temp[i-gap];

  for(int i=gap+rd; i<7; i++) cardarr[i] = temp[i];

  cout << "Top " << rd << " cards are inserted in the middle / South vs North "<< endl;
  
}

void discard_top_card(char *cardarr[], int rd)
{
  for(int i=0; i<7-rd; i++) cardarr[i] = cardarr[i+rd]; 

  cout << "Top " << rd << " cards are discarded" << endl;
  
}

void flip1card(char *cardarr[], int rd)
{
  for(int i=0; i<7; i++) {
    char *temp = cardarr[0]; 
    for(int j=0; j<rd-1; j++) cardarr[j] = cardarr[j+1];
    cardarr[rd-1] = temp;

    //for(int j=0; j<rd; j++) cout << i << " ... " << cardarr[j] << endl;
  }
}
