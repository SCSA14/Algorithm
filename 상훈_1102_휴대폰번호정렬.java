import java.util.*;

public class Main {

	static int N;
	static int[] a;
	static String[] b;
	static String[] c;

	public static void main(String[] args) {

		// �Է¹޴� �κ�
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		a = new int[6];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		b = new String[N];
		for (int i = 0; i < b.length; i++) {
			b[i] = sc.next();
		}
		sc.close();
		List<String> list = new ArrayList<String>();
		// ���⼭���� �ۼ�
		for(int i=0;i<b.length;i++) {
			list.add(String.valueOf(b[i]));
		}
		
		Collections.sort(list);
		c = new String[N];
		int cnt=0;
		for(int i=0;i<a.length;i++) {
			for(int j=0;j<b.length;j++) {
				if(a[i]==list.get(j).charAt(2)-'0' && list.get(j).charAt(6)!='-') {
					c[cnt++]=list.get(j);
				}
			}
			for(int j=0;j<b.length;j++) {
				if(a[i]==list.get(j).charAt(2)-'0' && list.get(j).charAt(6)=='-') {
					c[cnt++]=list.get(j);
				}
			}
		}
		for(int i=0;i<c.length;i++) {
			System.out.println(c[i]);
		}
	}
}