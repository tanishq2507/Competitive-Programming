class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        numComponents = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find_parent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node]);
    }

    void make_union(int u, int v) {
        int up1 = find_parent(u);
        int up2 = find_parent(v);
        if (up1 != up2) {
            if (size[up1] >= size[up2]) {
                parent[up2] = up1;
                size[up1] += size[up2];
            } else {
                parent[up1] = up2;
                size[up2] += size[up1];
            }
            numComponents--; // Decrement number of components when union is performed
        }
    }

    int getNumComponents() const {
        return numComponents;
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
    int numComponents;
};
