/*
Problem in simple words:

You are given a tree with n nodes, rooted at node 1.
Each node may or may not contain a cat.

You start from node 1 and move only along tree edges.
Some leaf nodes represent restaurants.

There is a restriction:
On the path from node 1 to any restaurant, you are allowed to pass through
at most m consecutive nodes that contain cats.

Your task is to count how many restaurants (leaf nodes) can be reached
without ever exceeding this limit.

--------------------------------------------------

What we are doing:

This is a tree traversal problem, so we use Depth First Search (DFS).

While moving from the root to the leaves, we keep track of:
- how many cat-nodes we have visited consecutively so far

At each node:
- if the node has a cat, we increase the count
- if it does not, we reset the count to zero

If at any point the consecutive cat count becomes greater than m,
we stop exploring that path immediately because it is invalid.

--------------------------------------------------

When do we count a restaurant?

If we reach a leaf node and:
- the path never exceeded m consecutive cat nodes

then that leaf is a valid restaurant and we increment the answer.

--------------------------------------------------

Why this works:

- The graph is a tree, so there are no cycles.
- DFS naturally explores root-to-leaf paths.
- Carrying the consecutive cat count is easy during recursion.
- Early stopping (pruning) avoids unnecessary traversal.

--------------------------------------------------

Time Complexity:
O(n), since each node is visited at most once.

Space Complexity:
O(n), due to recursion stack and adjacency list.
*/
//--------------------------submission link--------------------------------------------------------
// https://codeforces.com/contest/580/submission/356705245

import java.util.*;
import java.io.*;

public class Solution1 {
    static List<Integer>[] adj;
    static int[] cat;
    static int n, m, validRestaurants = 0;

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader();
        n = fr.nextInt();
        m = fr.nextInt();

        cat = new int[n + 1];
        for (int i = 1; i <= n; i++) cat[i] = fr.nextInt();

        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            int u = fr.nextInt();
            int v = fr.nextInt();
            adj[u].add(v);
            adj[v].add(u);
        }

        dfs(1, 0, 0);
        System.out.println(validRestaurants);
    }

    static void dfs(int u, int p, int consecutive) {
        int currentConsecutive = (cat[u] == 1) ? consecutive + 1 : 0;

        if (currentConsecutive > m) return;

        boolean isLeaf = true;
        for (int v : adj[u]) {
            if (v != p) {
                isLeaf = false;
                dfs(v, u, currentConsecutive);
            }
        }

        if (isLeaf) {
            validRestaurants++;
        }
    }

    static class FastReader {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    return null;
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
