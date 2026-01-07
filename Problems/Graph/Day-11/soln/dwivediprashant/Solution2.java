/*
This program works on a tree where two players start from different nodes.

Alice starts at node 1.
Bob starts at node x.

Both move one edge at a time. Alice wants to stay ahead of Bob for as long as possible.

The key idea is distance.
For every node, we compare:
- how long it takes Alice to reach it
- how long it takes Bob to reach it

If Bob can reach a node earlier or at the same time, that node is unsafe.
Alice only benefits from nodes where she arrives strictly later than Bob.

Once Alice reaches such a node, she can keep moving back and forth along the path
she used to reach it. That effectively doubles the number of moves she survives.
So for each safe node, the survival time is twice Alice’s distance to that node.

To compute distances efficiently:
- Run BFS from node 1 to get Alice’s distances
- Run BFS from node x to get Bob’s distances

Then scan all nodes and take the maximum value of:
    2 × distance from Alice
only for nodes where Alice’s distance is greater than Bob’s.

The graph is a tree and unweighted, so BFS gives correct shortest distances.
The entire solution runs in linear time.

This is a distance-comparison problem on trees, solved with two BFS traversals
and a final pass to compute the answer.
*/

//-----------------------------submission link---------------------------------
//  https://codeforces.com/contest/813/submission/356703330

import java.util.*;
import java.io.*;

public class Solution2 {
    static List<Integer>[] adj;
    static int n;

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader();
        n = fr.nextInt();
        int x = fr.nextInt();

        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            int u = fr.nextInt();
            int v = fr.nextInt();
            adj[u].add(v);
            adj[v].add(u);
        }

        int[] distAlice = bfs(1);
        int[] distBob = bfs(x);

        int maxMoves = 0;
        for (int i = 1; i <= n; i++) {
            if (distAlice[i] > distBob[i]) {
                maxMoves = Math.max(maxMoves, distAlice[i] * 2);
            }
        }

        System.out.println(maxMoves);
    }

    static int[] bfs(int start) {
        int[] d = new int[n + 1];
        Arrays.fill(d, -1);
        Queue<Integer> q = new LinkedList<>();

        q.add(start);
        d[start] = 0;

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.add(v);
                }
            }
        }
        return d;
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
