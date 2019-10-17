#include "Search.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main(int argc, char* argv[]) {
    Search s;
    fstream output("output.txt");
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        int source = rand() % 15;
        int destination = rand() % 15;

        cout << "src: " << source << endl;
        cout << "dest: " << destination << endl;
        for(int j = 0; j < 12; j++) {
            s.load();
            s.select(j);
            //s.execute(atoi(argv[1]), atoi(argv[2]));
            s.execute(source, destination);
            s.stat();
            //s.save(output);
        }
        cout << endl << endl << endl;
        cout << "LOOPNUMBER: " << i << endl;
        cout << endl << endl;
    }
    s.format_report_matrix();

    return 0;
}

// int main() {
//     SearchAlgorithm sa = SearchAlgorithm("large50/largeGraph.txt", "large50/largeWeights.txt", "large50/largePositions.txt");
//     //SearchAlgorithm sa = SearchAlgorithm("datafiles/graph.txt", "datafiles/weights.txt", "datafiles/positions.txt");
//     sa.dfs_i_l(1, 16);
//     cout << endl;
//     sa.bfs_i_l(1, 16);
//     cout << endl;

//     sa.dfs_i_m(1, 16);
//     cout << endl;
//     sa.bfs_i_m(1, 16);
//     cout << endl;
    
//     //error
//     sa.dfs_r_l(1, 16);
//     cout << endl;
//     sa.bfs_r_l(1, 16);
//     cout << endl;

//     sa.dfs_r_m(1, 16);
//     cout << endl;
//     sa.bfs_r_m(1, 16);
//     cout << endl;

//     sa.dijkstra_l(1, 16);
//     sa.dijkstra_m(1, 16);

//     //sa.a_star_l();
//     return 0;
// }