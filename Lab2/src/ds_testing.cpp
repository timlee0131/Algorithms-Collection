// #include "ds_testing.h"

// void ds_testing::construct() {
//     // LINK_LIST CONSTRUCTION
//     link_list.insert_back(1);                   link_list.insert_back(2);
//     link_list.insert_back(3);                   link_list.insert_back(4);
//     link_list.insert_back(5);                   link_list.insert_back(6);
//     link_list.insert_back(7);                   link_list.insert_back(8);
//     link_list.insert_back(9);                   link_list.insert_back(10);
//     link_list.insert_back(11);                  link_list.insert_back(12);
//     link_list.insert_back(13);                  link_list.insert_back(14);
//     link_list.insert_back(15);                  link_list.insert_back(16);
//     link_list.insert_back(17);                  link_list.insert_back(18);
//     link_list.insert_back(19);                  link_list.insert_back(20);
//     link_list.insert_back(21);                  link_list.insert_back(22);
//     link_list.insert_back(23);                  link_list.insert_back(24);
//     link_list.insert_back(25);                  link_list.insert_back(26);
//     link_list.insert_back(27);                  link_list.insert_back(28);
//     link_list.insert_back(29);                  link_list.insert_back(30); 

//     //ADJACENCY LIST CONSTRUCTION
//     adj_list.insert_back(1);                    adj_list.insert_back(2);
//     adj_list.insert_back(3);                    adj_list.insert_back(4);
//     adj_list.insert_back(5);                    adj_list.insert_back(6);
//     adj_list.insert_back(7);                    adj_list.insert_back(8);
//     adj_list.insert_back(9);                    adj_list.insert_back(10); 

//     for(int i = 0; i < 10; i++) {
//         for(int j = 0; j < 10; j++) {
//             adj_list[i] -> get_edges().insert_back(j);
//         }
//     }

//     //ADJACENCY MATRIX CONSTRUCTION
//     adj_matrix = ds_adjmatrix<int>(2);
//     adj_matrix.add_edge(0, 1, 10.5);
//     adj_matrix.add_edge(1, 0,5.5);

//     cout << "Testing completed" << endl; 
// }

// void ds_testing::display() {
//     link_list.display();
//     adj_list.display();
//     adj_matrix.display();
// }