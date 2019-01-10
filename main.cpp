#include <iostream>
#include "MySerialServer.h"
#include "MyClientHandler.h"
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

using namespace server_side;
using namespace std;

int main() {
    Server* mySerialServer = new MySerialServer();
    Searcher<string>* d = new ASTar<string>();
    Solver<string, string>* solver =new MatrixSolver<string, string>(d);
    CacheManager<string,string> *fileCacheManager = new FileCacheManager<string,string>();
    ClientHandler* clientHandler = new MyClientHandler(solver, fileCacheManager);
    cout<< "start mySerialServer" << endl;
    mySerialServer->open(5400, clientHandler);
    cout<< "end mySerialServer" <<endl;
    delete fileCacheManager;


//    Searcher<string>* d = new DFS<string>();
//    Solver<string, string>* solver2 =new MatrixSolver<string, string>(d);
//    string result2 = solver2->solve("1,2,3;4,5,6;7,8,9;end;0,0;2,2");
//    cout << "DFS: " + result2 << endl;


//   string temp="";
//    Searcher<string>* s = new DFS<string>();
//    Solver<string, string>* solver1 =new MatrixSolver<string, string>(s);
//    for(int i=0;i<10;i++){
//        for (int j = 0; j <9 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;9,9;";
//    string result1 = solver1->solve(temp);
//    cout << " 10x10: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<15;i++){
//        for (int j = 0; j <14 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;14,14";
//    result1 = solver1->solve(temp);
//    cout << " 15x15: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<18;i++){
//        for (int j = 0; j <17 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;17,17";
//    result1 = solver1->solve(temp);
//    cout << " 18x18: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<20;i++){
//        for (int j = 0; j <19 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;19,19";
//    result1 = solver1->solve(temp);
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//     result1 = solver1->solve(temp);
//    cout << " 20x20: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<25;i++){
//        for (int j = 0; j <24 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;24,24";
//     result1 = solver1->solve(temp);
//    cout << " 25x25: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<30;i++){
//        for (int j = 0; j <29 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;29,29";
//     result1 = solver1->solve(temp);
//    cout << " 30x30: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<35;i++){
//        for (int j = 0; j <34 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;34,34";
//     result1 = solver1->solve(temp);
//    cout << " 35x35: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<40;i++){
//        for (int j = 0; j <39 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;39,39";
//     result1 = solver1->solve(temp);
//    cout << " 40x40: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<45;i++){
//        for (int j = 0; j <44 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;44,44";
//     result1 = solver1->solve(temp);
//    cout << " 45x45: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//     solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<50;i++){
//        for (int j = 0; j <49 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;49,49";
//     result1 = solver1->solve(temp);
//    cout << " 50x50: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//


//    Searcher<string>* d = new DFS<string>();
//    Solver<string, string>* solver2 =new MatrixSolver<string, string>(d);
//    string result2 = solver2->solve("1,2,3;4,5,6;7,8,9;end;0,0;2,2");
//    cout << "DFS: " + result2 << endl;

//    Searcher<string>* b = new BestFirstSearch<string>();
//    Solver<string, string>* solver3 =new MatrixSolver<string, string>(b);
//    string result3 = solver3->solve("1,2,3,4;3,4,5,6;6,7,8,9;5,6,7,8;end;0,0;3,3");
//   // string result3 = solver3->solve("0,0,0,0;90,4,5,0;0,7,8,90;0,6,7,0;end;0,0;3,3");
//
//    cout << "BestFirstSerch : " + result3 << endl;
//    cout <<  b->getNumberOfNodesEvaluated() << endl;


//    Searcher<string>* l = new DFS<string>();
//    Solver<string, string>* solver4 =new MatrixSolver<string, string>(l);
//    string result4 = solver4->solve("1,2,1,3,4,5;4,1,6,3,6,8;2,0,9,2,3,6;2,8,9,6,12,4;3,5,6,8,23,4;2,3,4,5,6,8;end;0,0;5,5");
//    cout << "dfs :  : " + result4 << endl;
//    cout << l->getNumberOfNodesEvaluated() << endl;
////
//
//    string temp="";
//    Searcher<string>* s = new DFS<string>();
//    Solver<string, string>* solver1 =new MatrixSolver<string, string>(s);
//    for(int i=0;i<10;i++){
//        for (int j = 0; j <9 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;9,9;";
//    string result1 = solver1->solve(temp);
//    cout<<result1<<endl;
//    cout << " 10x10: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<15;i++){
//        for (int j = 0; j <14 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;14,14";
//    result1 = solver1->solve(temp);
//    cout << " 15x15: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<18;i++){
//        for (int j = 0; j <17 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;17,17";
//    result1 = solver1->solve(temp);
//    cout << " 18x18: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<20;i++){
//        for (int j = 0; j <19 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;19,19";
//    result1 = solver1->solve(temp);
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    result1 = solver1->solve(temp);
//    cout << " 20x20: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<25;i++){
//        for (int j = 0; j <24 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;24,24";
//    result1 = solver1->solve(temp);
//    cout << " 25x25: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<30;i++){
//        for (int j = 0; j <29 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;29,29";
//    result1 = solver1->solve(temp);
//    cout << " 30x30: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<35;i++){
//        for (int j = 0; j <34 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;34,34";
//    result1 = solver1->solve(temp);
//    cout << " 35x35: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<40;i++){
//        for (int j = 0; j <39 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;39,39";
//    result1 = solver1->solve(temp);
//    cout << " 40x40: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<45;i++){
//        for (int j = 0; j <44 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;44,44";
//    result1 = solver1->solve(temp);
//    cout << " 45x45: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
//    s = new DFS<string>();
//    solver1 =new MatrixSolver<string, string>(s);
//    temp="";
//    for(int i=0;i<50;i++){
//        for (int j = 0; j <49 ; ++j) {
//            temp+=to_string(j)+",";
//        }
//        temp+="9;";
//    }
//    temp+="end;";
//    temp+="0,0;49,49";
//    result1 = solver1->solve(temp);
//    cout << " 50x50: " + to_string(s->getNumberOfNodesEvaluated()) << endl;
//
    return 0;
}