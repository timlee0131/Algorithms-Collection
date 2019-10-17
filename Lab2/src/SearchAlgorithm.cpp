#include "SearchAlgorithm.h"
#include <math.h>
# define INF 0x3f3f3f3f

//#include "ds_node.h"

SearchAlgorithm::SearchAlgorithm(string filename, string filename2, string filename3) {
    pp.parse_graph(filename, filename2, filename3);
    list = pp.get_list();
    //matrix = ds_adjmatrix<data_box>(pp.get_matrix().get_vertices());
    matrix = pp.get_matrix();
    //pp.list_display();
    //pp.matrix_display_weight();
}


void SearchAlgorithm::dfs_i_l(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    stack<data_box> stack;
    vector<data_box> path;
    bool* visited = new bool[list.get_size()];
    for(int i = 0; i < list.get_size(); i++) {
        visited[i] = false;
    }
    visited[src] = true;
    stack.push(box1);

    while(!stack.empty()) {
        box1 = stack.top();
        stack.pop();
        //cout << box1.node << " ";
        path.push_back(box1);
        if(box1.node == dest) {
            data_box dest_box;
            dest_box.node = dest;
            path.push_back(dest_box);
            // cout << "dfs iterative list: ";
            // for(int i = 0; i < path.size(); i++) {
            //     cout << path[i].node << " ";
            // }   cout << endl;
            dfs_iterative_list = path;
        }

        ds_node<data_box>* curr = list.find(box1) -> get_edges().get_head();
        while(curr != nullptr) {
            if(!visited[curr -> get_data().node]) {
                visited[curr -> get_data().node] = true;
                stack.push(curr -> get_data());
            }
            curr = curr -> get_next();
        }
    }
    return;
}

void SearchAlgorithm::dfs_i_m(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    stack<data_box> stack;
    vector<data_box> path;

    // for(int i = 0; i < matrix.get_vertices(); i++) {
    //     for(int j = 0; j < matrix.get_vertices(); j++) {
    //         cout << matrix.get_matrix()[i][j].get_data().weight << " ";
    //     }cout << endl;
    // }   cout << "matrix prints fine" << endl; 

    bool* visited = new bool[matrix.get_vertices() + 1];
    for(int i = 0; i <= matrix.get_vertices(); i++) {
        visited[i] = false;
    }

    stack.push(box1);
    visited[src] = true;
    if(src == dest) {
        return;
    }

    while(!stack.empty()) {
        data_box last = stack.top();
        stack.pop();
        if(last == box2) {
            path.push_back(matrix.find(box2).get_data());
            // cout << "dfs iterative matrix: ";
            // for(int i = 0; i < path.size(); i++) {
            //     cout << path[i].node << " ";
            // }   cout << endl;
            dfs_iterative_matrix = path;
            break;
        }
        path.push_back(matrix.find(last).get_data());

        for(int i = 0; i < matrix.get_vertices(); i++) {
            if(matrix.edge_exists(last.node, i) && !visited[i]) {
                data_box box3;
                box3.node = i;
                stack.push(box3);
                visited[i] = true;
            }
        }
    }
    cout << endl;
    //delete [] visited;
    return;
}

void SearchAlgorithm::bfs_i_l(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    queue<data_box> queue;
    vector<data_box> path;
    bool* visited = new bool[list.get_size()];
    for(int i = 0; i < list.get_size(); i++) {
        visited[i] = false;
    }
    visited[src] = true;
    queue.push(box1);

    while(!queue.empty()) {
        box1 = queue.front();
        queue.pop();
        //cout << box1.node << " ";
        path.push_back(box1);
        if(box1.node == dest) {
            data_box dest_box;
            dest_box.node = dest;
            path.push_back(dest_box);
            // cout << "bfs iterative list: ";
            // for(int i = 0; i < path.size(); i++) {
            //     cout << path[i].node << " ";
            // }   cout << endl;
            bfs_iterative_list = path;
        }

        ds_node<data_box>* curr = list.find(box1) -> get_edges().get_head();
        while(curr != nullptr) {
            if(!visited[curr -> get_data().node]) {
                visited[curr -> get_data().node] = true;
                queue.push(curr -> get_data());
            }
            curr = curr -> get_next();
        }
    }
    
    return;
}

void SearchAlgorithm::bfs_i_m(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    queue<data_box> queue;
    vector<data_box> path;

    // for(int i = 0; i < matrix.get_vertices(); i++) {
    //     for(int j = 0; j < matrix.get_vertices(); j++) {
    //         cout << matrix.get_matrix()[i][j].get_data().weight << " ";
    //     }cout << endl;
    // }   cout << "matrix prints fine" << endl; 

    bool* visited = new bool[matrix.get_vertices() + 1];
    for(int i = 0; i <= matrix.get_vertices(); i++) {
        visited[i] = false;
    }

    queue.push(box1);
    visited[src] = true;
    if(src == dest) {
        return;
    }

    while(!queue.empty()) {
        data_box last = queue.front();
        queue.pop();
        if(last == box2) {
            path.push_back(matrix.find(box2).get_data());
            //cout << "bfs iterative matrix: ";
            // for(int i = 0; i < path.size(); i++) {
            //     cout << path[i].node << " ";
            // }   cout << endl;
            bfs_iterative_matrix = path;
            break;
        }
        path.push_back(matrix.find(last).get_data());

        for(int i = 0; i < matrix.get_vertices(); i++) {
            if(matrix.edge_exists(last.node, i) && !visited[i]) {
                data_box box3;
                box3.node = i;
                queue.push(box3);
                visited[i] = true;
            }
        }
    }
    cout << endl;
    delete [] visited;
    return;
}

void SearchAlgorithm::dfs_r_l(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    queue<data_box> queue;
    vector<data_box> path;

    bool* visited = new bool[list.get_size() ];
    path.push_back(box1);
    dfs_r_l_recursion(box1, box2, visited, path);
    //delete [] visited;
}

void SearchAlgorithm::dfs_r_l_recursion(data_box d1, data_box d2, bool* visited, vector<data_box> path) {
    visited[d1.node] = true;
    if(d1 == d2) {
        //cout << "dfs recursive list: ";
        path.push_back(d2);
        // for(int i = 0; i < path.size(); i++) {
        //     cout << path[i].node << " ";
        // }   cout << endl;
        dfs_recursive_list = path;
        return;
    }
    ds_node<data_box>* curr = list.find(d1) -> get_edges().get_head();
    while(curr != nullptr) {
        if(!visited[curr -> get_data().node]) {
            data_box box3;
            box3.node = curr -> get_data().node;
            path.push_back(box3);
            return dfs_r_l_recursion(box3, d2, visited, path);
            path.erase(path.begin() + curr -> get_data().node);
        }
        curr = curr -> get_next();
    }
    return dfs_r_l_recursion(list.find(d1) ->get_next() ->get_data(), d2, visited, path);
    visited[d1.node] = false;
}

void SearchAlgorithm::bfs_r_l(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    stack<data_box> stack;
    vector<data_box> path;

    bool* visited = new bool[list.get_size() ];
    path.push_back(box1);
    bfs_r_l_recursion(box1, box2, visited, path);
    //delete [] visited;
}

void SearchAlgorithm::bfs_r_l_recursion(data_box d1, data_box d2, bool* visited, vector<data_box> path) {
    visited[d1.node] = true;
    if(d1 == d2) {
        // cout << "bfs recursive list: ";
        // for(int i = 0; i < path.size(); i++) {
        //     cout << path[i].node << " ";
        // }   cout << endl;
        bfs_recursive_list = path;
        return;
    }
    ds_node<data_box>* curr = list.find(d1) -> get_edges().get_head();
    while(curr != nullptr) {
        if(!visited[curr -> get_data().node]) {
            data_box box3;
            box3.node = curr -> get_data().node;
            path.push_back(box3);
            return bfs_r_l_recursion(box3, d2, visited, path);
            path.erase(path.begin() + curr -> get_data().node);
        }
        curr = curr -> get_next();
    }
    return bfs_r_l_recursion(list.find(d1) ->get_next() ->get_data(), d2, visited, path);
    visited[d1.node] = false;
}

void SearchAlgorithm::dfs_r_m(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    stack<data_box> stack;
    vector<data_box> path;
    bool* visited = new bool[matrix.get_vertices()];
    for(int i = 0; i < matrix.get_vertices(); i++) {
        visited[i] = false;
    }
    visited[src] = true;
    path.push_back(box1);
    stack.push(box1);
    dfs_r_m_recursion(box1, box2, stack, visited, path);
    //delete [] visited;
}

void SearchAlgorithm::dfs_r_m_recursion(data_box d1, data_box d2, stack<data_box>& stack, bool* visited, vector<data_box> path) {
    if(stack.empty())
        return;
    
    data_box last = stack.top();
    stack.pop();
    path.push_back(last);
    if(last == d2) {
        // cout << "dfs recursive matrix: ";
        // for(int i = 0; i < path.size(); i++) {
        //     cout << path[i].node << " ";
        // }   cout << endl;
        dfs_recursive_matrix = path;
        return;
    }

    path.push_back(last);
    data_box box;
    for(int i = 0; i < matrix.get_vertices(); i++) {
        if(matrix.edge_exists(last.node, i) && !visited[i]) {
            box.node = i;
            stack.push(box);
            visited[i] = true;
        }
    }
    dfs_r_m_recursion(matrix.find(box).get_data(),d2, stack, visited, path);
}

void SearchAlgorithm::bfs_r_m(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    queue<data_box> queue;
    vector<data_box> path;
    bool* visited = new bool[matrix.get_vertices()];
    for(int i = 0; i < matrix.get_vertices(); i++) {
        visited[i] = false;
    }

    visited[src] = true;
    path.push_back(box1); 
    queue.push(box1);
    bfs_r_m_recursion(box1, box2, queue, visited, path);
    //delete [] visited;
}

void SearchAlgorithm::bfs_r_m_recursion(data_box d1, data_box d2, queue<data_box>& queue, bool* visited, vector<data_box> path) {
    if(queue.empty()) {
        return;
    }
    
    data_box last = queue.front();
    queue.pop();
    path.push_back(last);
    if(last == d2) {
        // cout << "bfs recursive matrix: ";
        // for(int i = 0; i < path.size(); i++) {
        //     cout << path[i].node << " ";
        // }   cout << endl;
        bfs_recursive_matrix = path;
        return;
    }

    path.push_back(last);
    data_box box;
    for(int i = 0; i < matrix.get_vertices(); i++) {
        if(matrix.edge_exists(last.node, i) && !visited[i]) {
            box.node = i;
            queue.push(box);
            visited[i] = true;
        }
    }
    return bfs_r_m_recursion(matrix.find(box).get_data(),d2,queue, visited, path);
}

void SearchAlgorithm::dijkstra_l(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    vector<data_box> path;

    priority_queue<data_box> pq;
    vector<int> dist (list.get_size(), INF);
    pq.push(box1);
    dist[src] = 0;

    while(!pq.empty()) {
        data_box last = pq.top();
        pq.pop();

        if(last.node == dest) {
            path.push_back(box2);
            // cout << "dijkstra list: ";
            // for(int i = 0; i < path.size(); i++) {
            //     cout << path[i].node << " ";
            // }   cout << endl;
            dijkstra_list = path;
        }

        path.push_back(last);

        ds_node<data_box>* curr = list.find(last) -> get_edges().get_head();
        while(curr != nullptr) {
            int v_label = curr -> get_data().node;
            int weight_label = curr -> get_data().weight;
            
            if(dist[v_label] > dist[last.node] + weight_label) {
                dist[v_label] = dist[last.node] + weight_label;
                pq.push(curr -> get_data());
            }
            curr = curr -> get_next();
        }
    }

    return;
}

void SearchAlgorithm::dijkstra_m(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    vector<data_box> path;

    priority_queue<data_box> pq;
    vector<int> dist (matrix.get_vertices(), INF);
    pq.push(box1);
    dist[src] = 0;

    while(!pq.empty()) {
        data_box last = pq.top();
        pq.pop();

        if(last.node == dest) {
            path.push_back(box2);
            // cout << "dijkstra matrix: ";
            // for(int i = 0; i < path.size(); i++) {
            //     cout << path[i].node << " ";
            // }   cout << endl;
            dijkstra_matrix = path;
        }

        path.push_back(last);

        for(int i = 0; i < matrix.get_vertices(); i++) {
            if(matrix.edge_exists(last.node, i) ) {
                data_box box3;
                box3.node = i;
                int v_label = i;
                int weight_label = matrix.find(box3).get_data().weight;

                if(dist[v_label] > dist[last.node] + weight_label) {
                    dist[v_label] = dist[last.node] + weight_label;
                    pq.push(matrix.find(box3).get_data());
                }
            }
        }        
    }
    return;
}

double SearchAlgorithm::get_heuristic(data_box src, data_box curr) {
    double dist = (curr.x - src.x) * (curr.x - src.x) + (curr.y - src.y) * (curr.y - src.y) + (curr.z - src.z) * (curr.z - src.z);
    double g = sqrt(dist);
    //double h = 1.0 + (list.find(src) -> get_edges().find(curr) ->get_data().weight);

    return g;
}

vector<data_box> SearchAlgorithm::a_star_l(int src, int dest) {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    vector<data_box> path;
    vector<node> openlist, closedlist;
    node s;
    s.box = list.find(box1) ->get_data();

    openlist.push_back(s);

    while(!openlist.empty()) {
        int pos;
        for(int i = 0; i < openlist.size(); i++) {
            if(s.g + s.h >= openlist[i].g + openlist[i].h) {
                s = openlist[i];
                pos = i;
            }
            openlist.erase(openlist.begin() + pos);
        }

        ds_node<data_box>* curr = list.find(s.box) ->get_edges().get_head();
        while(curr != nullptr) {
            node node_curr;
            node_curr.box = curr -> get_data();
            node_curr.parent = list.find(s.box) -> get_data();

            if(node_curr.box.node == dest) {
                cout << "a star list: ";
                for(int i = 0; i < path.size(); i++) {
                    cout << path[i].node << " ";
                }   cout << endl;
                break;
            }
            node_curr.g = s.g + get_heuristic(s.box, node_curr.box);
            node_curr.h = get_heuristic(node_curr.box, list.find(box2) -> get_data());
            node_curr.f = node_curr.g + node_curr.h;

            for(int i = 0; i < openlist.size(); i++) {
                if(openlist[i].g == node_curr.g && openlist[i].f <= node_curr.f)
                    continue;
            }

            for(int i = 0; i < closedlist.size(); i++) {
                if(closedlist[i].g == node_curr.g) {
                    if(closedlist[i].f <= node_curr.f)
                        continue;
                    else
                        openlist.push_back(closedlist[i]);
                }
            }

            path.push_back(node_curr.box);
            curr = curr -> get_next();
        }
        closedlist.push_back(s);
    }
    return path;
}