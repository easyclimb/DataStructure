typedef int vertex_t;
typedef int weight_t;

struct neighbour {
  vertex_t dst;
  weight_t weight;
  neighbour(vertex_t v, weight_t w) : dst(v), weight(w) {}
};

typedef vector<vector<neighbour>> Graph;

void Di
