const int numbSommet = 15;

int orderG(){
return 15;}

int sizeG(){
return 24;
}

int graph[15][15] = {
{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
{0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0}
};


int are_adjacent(int u, int v){
  if(0<= u && 0<=v && u<orderG() && v<orderG()){
      return graph[u][v];
  }
  return 0;
}


///// G30 /////

//int orderG(){
//    return 30;
//}

//int sizeG(){
//    return 15*29;
//}

//int are_adjacent(int u, int v){
//    if(0<=u && 0<=v && u<orderG() && v<orderG()){
//        if (u>v)
//            return (u-v)%30;
//        else
//            return (v-u)%30;
//    }
//    return 0;
//}

///// Graphe de Chavatal /////

// X(G) = 4
// 4-regulier

//int graph[12][12] = {
//  // 0  1  2  3  4  5  6  7  8  9 10 11
//    {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1}, //0
//    {1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, //1
//    {0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0}, //2
//    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0}, //3
//    {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0}, //4
//    {0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0}, //5
//    {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0}, //6
//    {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1}, //7
//    {0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, //8
//    {0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0}, //9
//    {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, //10
//    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0}  //11
//};

//int orderG(){
//return 12;}

//int sizeG(){
//return 24;
//}

//int are_adjacent(int u, int v){
//  if(0<= u && 0<=v && u<orderG() && v<orderG()){
//      return graph[u][v];
//  }astakhan.com
//  return 0;
//}

///// G40 /////

//int orderG(){
//    return 40;
//}

//int sizeG(){
//    return  700;
//}

//int are_adjacent(int u, int v){
//    if(0<=u && 0<=v && u<orderG() && v<orderG()){
//        if (u>v)
//            return (u-v)%8;
//        else
//            return (v-u)%8;
//    }
//    return 0;
//}
















