const int numbSommet = 9;

int orderG(){
    return numbSommet;
}

int sizeG(){
    return 48;
}

int graph[numbSommet][numbSommet] = {
    // 0  1  2  3  4  5  6  7  8
    {0, 1, 1, 1, 0, 0, 0, 0, 0}, //0
    {1, 0, 1, 0, 0, 0, 0, 0, 0}, //1
    {1, 1, 0, 0, 0, 1, 1, 0, 0}, //2
    {1, 0, 0, 0, 1, 1, 0, 0, 0}, //3
    {0, 0, 0, 1, 0, 1, 0, 0, 0}, //4
    {0, 0, 1, 1, 1, 0, 0, 0, 0}, // 5
    {0, 0, 1, 0, 0, 0, 0, 1, 1}, // 6
    {0, 0, 0, 0, 0, 0, 1, 0, 1}, // 7
    {0, 0, 0, 0, 0, 0, 1, 1, 0} // 8
};


int are_adjacent(int u, int v){
    if (0<= u && 0<=v && u<=numbSommet && v<=numbSommet){
        if(0<= u && 0<=v && u<orderG() && v<orderG()){
            return graph[u][v];
        }
        return 0;
    }
    else return (u-v == -1 || u-v==1 || u-v == -numbSommet|| u-v == numbSommet);
}

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

// Graphe de Chavatal
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
//  }
//  return 0;
//}


