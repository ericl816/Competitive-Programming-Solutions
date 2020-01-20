import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class DMOPC14SawmillScheme {

	static boolean[] sawmill = new boolean[1000000];
	static double[] prob = new double[1000000];

	public static void main (String[] args) throws IOException {
            BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
             StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
		for (int x = 0; x < n; x++)
			al.add(new ArrayList<Integer>());
		for (int x = 0; x < m; x++) {
                    st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			al.get(a).add(Integer.parseInt(st.nextToken()) - 1);
			sawmill[a] = true;
		}
		prob[0] = 1.0;
		for (int x = 0; x < n; x++) {
			double cnt = al.get(x).size();
			for (Integer i : al.get(x))
				prob[i] += prob[x] / cnt;
		}
		for (int x = 0; x < n; x++)
			if (!sawmill[x])
				System.out.println(prob[x]);
        }
	}