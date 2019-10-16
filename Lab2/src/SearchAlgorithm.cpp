#include "SearchAlgorithm.h"
//#include "ds_node.h"

SearchAlgorithm::SearchAlgorithm(int s, int d, string filename, string filename2, string filename3) {
    src = s;
    dest = d;
    cout << "initial dst: " << dest << endl; 
    pp.parse_graph(filename, filename2, filename3);
    cout << "parsing finished" << endl;
    list = pp.get_list();
    //matrix = ds_adjmatrix<data_box>(pp.get_matrix().get_vertices());
    matrix = pp.get_matrix();
    //pp.list_display();
    //pp.matrix_display_weight();
}


vector<data_box> SearchAlgorithm::dfs_i_l() {
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
            cout << "dfs iterative list: ";
            for(int i = 0; i < path.size(); i++) {
                cout << path[i].node << " ";
            }   cout << endl;
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

    return path;
}

vector<data_box> SearchAlgorithm::dfs_i_m() {
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
        return path;
    }

    while(!stack.empty()) {
        data_box last = stack.top();
        stack.pop();
        if(last == box2) {
            path.push_back(matrix.find(box2).get_data());
            cout << "dfs iterative matrix: ";
            for(int i = 0; i < path.size(); i++) {
                cout << path[i].node << " ";
            }   cout << endl;
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
    return path;
}

vector<data_box> SearchAlgorithm::bfs_i_l() {
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
            cout << "bfs iterative list: ";
            for(int i = 0; i < path.size(); i++) {
                cout << path[i].node << " ";
            }   cout << endl;
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
    
    return path;
}

vector<data_box> SearchAlgorithm::bfs_i_m() {
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
        return path;
    }

    while(!queue.empty()) {
        data_box last = queue.front();
        queue.pop();
        if(last == box2) {
            path.push_back(matrix.find(box2).get_data());
            cout << "bfs iterative matrix: ";
            for(int i = 0; i < path.size(); i++) {
                cout << path[i].node << " ";
            }   cout << endl;
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
    return path;
}

void SearchAlgorithm::dfs_r_l() {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    queue<data_box> queue;
    vector<data_box> path;

    bool* visited = new bool[list.get_size() ];
    path.push_back(box1);
    dfs_r_l_recursion(box1, box2, visited, path);
    delete [] visited;
}

void SearchAlgorithm::dfs_r_l_recursion(data_box d1, data_box d2, bool* visited, vector<data_box> path) {
    visited[d1.node] = true;
    if(d1 == d2) {
        cout << "dfs recursive list: ";
        for(int i = 0; i < path.size(); i++) {
            cout << path[i].node << " ";
        }   cout << endl;
        path = dfs_recursive_list;
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

void SearchAlgorithm::bfs_r_l() {
    data_box box1, box2;
    box1.node = src;
    box2.node = dest;
    stack<data_box> stack;
    vector<data_box> path;

    bool* visited = new bool[list.get_size() ];
    path.push_back(box1);
    bfs_r_l_recursion(box1, box2, visited, path);
    delete [] visited;
}

void SearchAlgorithm::bfs_r_l_recursion(data_box d1, data_box d2, bool* visited, vector<data_box> path) {
    visited[d1.node] = true;
    if(d1 == d2) {
        cout << "bfs recursive list: ";
        for(int i = 0; i < path.size(); i++) {
            cout << path[i].node << " ";
        }   cout << endl;
        path = bfs_recursive_list;
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

void SearchAlgorithm::dfs_r_m() {
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
    dfs_r_m_recursion(stack, visited, path);
    //delete [] visited;
}

void SearchAlgorithm::dfs_r_m_recursion(stack<data_box>& stack, bool* visited, vector<data_box> path) {
    if(stack.empty())
        return;
    
    data_box last = stack.top();
    stack.pop();
    path.push_back(last);
    if(last.node == dest) {
        cout << "dfs recursive matrix: ";
        for(int i = 0; i < path.size(); i++) {
            cout << path[i].node << " ";
        }   cout << endl;
        dfs_recursive_matrix = path;
        return;
    }

    path.push_back(last);

    for(int i = 0; i < matrix.get_vertices(); i++) {
        if(matrix.edge_exists(last.node, i) && !visited[i]) {
            data_box box;
            box.node = i;
            stack.push(box);
            visited[i] = true;
        }
    }
    dfs_r_m_recursion(stack, visited, path);
}

void SearchAlgorithm::bfs_r_m() {
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
    bfs_r_m_recursion(queue, visited, path);
    //delete [] visited;
}

void SearchAlgorithm::bfs_r_m_recursion(queue<data_box>& queue, bool* visited, vector<data_box> path) {
    if(queue.empty()) {
        return;
    }
    
    data_box last = queue.front();
    queue.pop();
    path.push_back(last);
    if(last.node == dest) {
        cout << "bfs recursive matrix: ";
        for(int i = 0; i < path.size(); i++) {
            cout << path[i].node << " ";
        }   cout << endl;
        bfs_recursive_matrix = path;
        return;
    }

    path.push_back(last);

    for(int i = 0; i < matrix.get_vertices(); i++) {
        if(matrix.edge_exists(last.node, i) && !visited[i]) {
            data_box box;
            box.node = i;
            queue.push(box);
            visited[i] = true;
        }
    }
    return bfs_r_m_recursion(queue, visited, path);
}