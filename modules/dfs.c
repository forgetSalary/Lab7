#include "dfs.h"

void dfs_log(int* component){
    _FOR_(i,buf_len(component)){
        printf("%d,",component[i]);
    }
    printf("\n");
}

void components_log(int** components){
    _FOR_(i,buf_len(components)){
        _FOR_(j,buf_len(components[i])){
            printf("%d,",components[i][j]);
        }
        printf("\n");
    }
}

void dists_log(int** dists,int* vertexes, int graph_size){
    int src_vertex_index;

    _FOR_(i,buf_len(dists)){
        src_vertex_index = get_int_index(dists[i],graph_size,0);
        printf("Distances from vertex '%d' to:\n",vertexes[src_vertex_index]);
        _FOR_(j,graph_size){
            printf("'%d': %d\n",vertexes[j],dists[i][j]);
        }
        printf("\n");
    }
}

void hardStack_matrix_dist(mtrx_grph_t* graph, int v_index, numbers_t* dist){
    printf("%d,",graph->vertexes[v_index]);
    for (int i=0; i<graph->size; i++){
        if (graph->matrix[v_index][i] && dist->data[i]==-1){
            dist->data[i] = dist->data[v_index]+1;
            hardStack_matrix_dist(graph,i,dist);
        }
    }
}

void hardStack_lists_dist(list_graph_t* graph,int v_index, int* dist, int** component, bool* visited){
    node_t* next = graph->lists[v_index]->head;
    int next_index;

    buf_push((*component),v_index);
    visited[v_index] = true;
    for (int i=0; i<graph->lists[v_index]->depth; i++){
        next_index=get_vertex_index(graph->vertexes,get_vrtx_name(next->value),graph->size);
        if (dist[next_index]==-1) {
            dist[next_index] = dist[v_index]+1;
            hardStack_lists_dist(graph, next_index,dist,component,visited);
        }
        next = next->next;
    }
}

void dfs_matrix(mtrx_grph_t* graph, int v_index, numbers_t* dist){
    fill_num(dist,-1);
    dist->data[v_index] = 0;
    hardStack_matrix_dist(graph,v_index,dist);
    printf("\n\n");
}

void dfs_lists(list_graph_t* graph, int v_index, int* dist, int** component, bool* visited){
    dist[v_index] = 0;
    hardStack_lists_dist(graph,v_index,dist,component,visited);
}

void hard_stack_matrix(mtrx_grph_t* graph, bool* visited, int v_index){
    visited[v_index]=true;

    printf("%d,",graph->vertexes[v_index]);
    for (int i=0; i<graph->size; i++){
        if (graph->matrix[v_index][i] && !visited[i]){
            hard_stack_matrix(graph,visited,i);
        }
    }

}

void virtual_stack_matrix(mtrx_grph_t* graph, bool* visited, int v_index){
    list_t* vrtx_stack = list_create();
    list_t* cycle_states_stack = list_create();

    int i=0;
    int current_v_index=v_index;

    visited[v_index]=true;
    printf("%d,",graph->vertexes[v_index]);

    int* tail;
    for (i; i<graph->size; i++){
        if (graph->matrix[v_index][i] && !visited[i]){
            printf("%d,",graph->vertexes[i]);
            visited[i]=true;

            append(vrtx_stack,new(int));
            append(cycle_states_stack,new(int));

            _VALUE_OF(int,cycle_states_stack->tail->value)=i;
            _VALUE_OF(int,vrtx_stack->tail->value)=v_index;

            current_v_index=i;
            i=-1;
        }

        v_index = current_v_index;

        if ((i+1)==graph->size){
            if (cycle_states_stack->tail){
                tail = (int *)list_pop(cycle_states_stack);
                i = _VALUE_OF(int,tail)-1;
                del(tail);

                tail = (int *)list_pop(vrtx_stack);
                current_v_index= _VALUE_OF(int,tail);
                del(tail);

                v_index = current_v_index;
            }
        }
    }
}

void hardStack_lists(list_graph_t* graph, bool* visited, int v_index){
    node_t* next = graph->lists[v_index]->head;
    int next_index;

    visited[v_index]=true;
    printf("%d,",graph->vertexes[v_index].name);
    for (int i=0; i<graph->lists[v_index]->depth; i++){
        next_index=get_vertex_index(graph->vertexes,get_vrtx_name(next->value),graph->size);
        if (!visited[next_index]) {
            visited[v_index]=true;
            hardStack_lists(graph, visited, next_index);
        }
        next = next->next;
    }
}

void components_dfs_Matrix(mtrx_grph_t* graph, void DFS(mtrx_grph_t*, bool* visited,int)){
    bool* visited = calloc(graph->size,1);

    int next_index=0;
    while (next_index!=-1){
        DFS(graph,visited,next_index);
        next_index = fst_false(visited,graph->size);
        printf("\n");
    }

    free(visited);
}

void components_dfs_Lists(list_graph_t* graph){
    bool* visited = calloc(graph->size,1);

    int next_index=0;
    int count = 0;
    while (next_index!=-1){
        hardStack_lists(graph,visited,next_index);
        next_index=fst_false(visited,graph->size);
        printf("\n");
        count++;
    }

    free(visited);
}

int*** components_and_dist_dfs_Lists(list_graph_t* graph){
    bool* visited = calloc(graph->size,1);

    int** cmpnts = NULL;
    int** dists = NULL;

    int next_index=0;
    int count = 0;
    while (next_index!=-1){
        buf_push(cmpnts,NULL);
        buf_push(dists,new_block(int,graph->size));
        fill(dists[count],graph->size,-1)
        dists[count][next_index] = 0;
        hardStack_lists_dist(graph,next_index,dists[count],&cmpnts[count],visited);
        next_index=fst_false(visited,graph->size);
        count++;
    }

    int*** result = new_block(int**,2);
    result[0]=cmpnts;
    result[1]=dists;

    free(visited);

    return result;
}