#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "StringReverse.h"
#include "Server.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MatrixSolver.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirsrtSearche.h"
#include "AStar.h"

//using namespace server_side;
using namespace std;

int main() {
//    Server* mySerialServer = new MySerialServer();
//    Solver<string,string> *stringReverse = new StringReverse();
//    CacheManager<string,string> *fileCacheManager = new FileCacheManager<string,string>();
//    ClientHandler* clientHandler = new MyTestClientHandler <string, string> (stringReverse, fileCacheManager);
//    cout<< "start mySerialServer" << endl;
//    mySerialServer->open(5400, clientHandler);
//    cout<< "end mySerialServer" <<endl;
/*
    Searcher<string>* s = new BFS<string>();
    Solver<string, string>* solver1 =new MatrixSolver<string, string>(s);
    string result = solver1->solve("1,2,3;4,5,6;7,8,9;end;0,0;2,2");
    cout << "BFS: " + result << endl;
*/
//    Searcher<string>* d = new DFS<string>();
//    Solver<string, string>* solver2 =new MatrixSolver<string, string>(d);
//    string result2 = solver2->solve("1,2,3;4,5,6;7,8,9;end;0,0;2,2");
//    cout << "DFS: " + result2 << endl;
//
//    Searcher<string>* b = new BestFirstSearch<string>();
//    Solver<string, string>* solver3 =new MatrixSolver<string, string>(b);
//    //string result3 = solver3->solve("1,40,50;4,5,6;7,8,9;end;0,0;2,2");
//    string result3 = solver3->solve("9,8,7;6,5,4;3,20,1;end;0,0;2,2");
//    cout << "BestFirstSerch : : " + result3 << endl;
    Searcher<string>* b = new ASTar<string>();
    Solver<string, string>* solver3 =new MatrixSolver<string, string>(b);
    //string result3 = solver3->solve("1,40,50;4,5,6;7,8,9;end;0,0;2,2");
    string result3 = solver3->solve("1,10,350;4,70,6;2,8,9;end;0,0;2,2");
    cout << "A* : : " + result3 << endl;



    return 0;
}