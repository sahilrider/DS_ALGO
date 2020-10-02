import java.util.*;

public class SortByFrequency{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.nextLine();
		System.out.println(frequencySort(s));
	}
	public static String frequencySort(String s) {
       if(s == null || s.length() <= 2){
           return s;
       }
        Map<Character,Integer> map = new HashMap<>();
        for(char x : s.toCharArray()){
            map.put(x,map.getOrDefault(x,0)+1);
        }
        PriorityQueue<Character> heap = new PriorityQueue<>(s.length(),(a,b)->map.get(b) - map.get(a));
        
        for(char x : map.keySet()){
            heap.offer(x);
        }
        StringBuilder sb = new StringBuilder();
        while(!heap.isEmpty()){
            char c = heap.poll();
            int count = map.get(c);
            for(int i = 0; i < count; i++){
                sb.append(c);
            }
        }
        return sb.toString();
    }
}