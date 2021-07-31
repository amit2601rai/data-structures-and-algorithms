/*Directed Graph*/
vi[] getDirectedGraph(int n, int m){
    vi v[n+1];
    while(m--){
        int x, y;
        s(x);
        s(y);
        v[x].pb(y);
    }
}

/*Un-Directed Graph*/
vi[] getUnDirectedGraph(int n, int m){
    vi v[n+1];
    while(m--){
        int x, y;
        s(x);
        s(y);
        v[x].pb(y);
        v[y].pb(x);
    }
}

/*Weighted Directed Graph*/
vii[] getWeightedDirectedGraph(int n, int m){
    vii v[n+1];
    while(m--){
        s(x);s(y);s(c);
        v[x].pb(mp(y,c));
    }
}

/*Weighted Un-Directed Graph*/
vii[] getWeightedUnDirectedGraph(int n, int m){
    vii v[n+1];
    while(m--){
        s(x);s(y);s(c);
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
    }
}
