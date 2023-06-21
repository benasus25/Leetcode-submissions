//{ Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String S = br.readLine().trim();
            int N = S.length();
            Solution ob = new Solution();
            String[] element = br.readLine().trim().split("\\s+");
		    int[] f = new int[N];
		    for(int i = 0; i < N; i++){
		        f[i] = Integer.parseInt(element[i]);
		    }
            ArrayList<String> res  = ob.huffmanCodes(S,f,N);
            for(int i = 0; i < res.size(); i++)
            {
                System.out.print(res.get(i)+" ");
            }
            System.out.println();
        }
	}
}
// } Driver Code Ends


//User function Template for Java


class Solution {
    ArrayList<String> ans = new ArrayList<>();
private class Node {
        int data;
        char val;
        Node left;
        Node right;

        Node(int d, char v) {
            data = d;
            val = v;
            left = null;
            right = null;
        }
    }

    private class Compare implements Comparator<Node> {
        public int compare(Node a, Node b) {
            if(a.data==b.data)return 1;
            return a.data - b.data;
        }
    }

    public void traverse(Node root, String temp) {
        if(root==null)return;
        if (root.left == null && root.right == null && Character.isLetter(root.val)) {
            ans.add(temp);
            return;
        }
        traverse(root.left, temp + "0");
        traverse(root.right, temp + "1");
    }

    public ArrayList<String> huffmanCodes(String S, int[] f, int N) {

        // Build priority queue with nodes
        PriorityQueue<Node> pq = new PriorityQueue<>(new Compare());
        for (int i = 0; i < N; i++) {
            Node temp = new Node(f[i], S.charAt(i));
            pq.add(temp);
        }

        // Build Huffman tree
        while (pq.size() > 1) {
            Node left = pq.peek();
            pq.poll();
            Node right = pq.peek();
            pq.poll();
            Node newNode = new Node(left.data + right.data, '-');
            newNode.left = left;
            newNode.right = right;
            pq.add(newNode);
        }

        Node root = pq.peek();
        String temp = "";
        traverse(root, temp);

        return ans;
    
    }
}