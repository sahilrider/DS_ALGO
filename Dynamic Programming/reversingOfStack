import java.io.*;
import java.util.*;
class GFG{
    Stack<Integer> s = new Stack<Integer>();
    
    void pushBack(int x,GFG g){
        if(g.s.isEmpty()){
            g.s.push(x);
            return;
        }else{
            int y = g.s.peek();
            g.s.pop();
            g.pushBack(x,g);
            g.s.push(y);
        }
    }
    
    void rev(GFG g){
        if(g.s.isEmpty()){
            return;
        }else{
            int x =g.s.peek();
            g.s.pop();
            g.rev(g);
            g.pushBack(x,g);
        }
    }
	public static void main (String[] args) {
	    GFG g = new GFG();
	    g.s.push(1);g.s.push(2);g.s.push(3);g.s.push(4);g.s.push(5);
	    System.out.println(g.s);
	    //g.pushBack(8,g);
	   g.rev(g);
	    System.out.println(g.s);
	    
	}
	
}
