/**
*	baekjoon online judge
*	No. 9935	¹®ÀÚ¿­ Æø¹ß
*	@author	peter9378
*	@date		2019.03.28
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String string = br.readLine();
        String bomb = br.readLine();
        Stack<Character> stack = new Stack<>();

        for(int i=string.length()-1;i>=0;i--){
            boolean flag = false;
            char c = string.charAt(i);

            stack.push(c);

            if(c == bomb.charAt(0) && stack.size()>=bomb.length()){
                flag = true;
                for(int j=0;j<bomb.length();j++){
                    if(bomb.charAt(j) != stack.get(stack.size()-1-j)){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int k=0;k<bomb.length();k++)
                        stack.pop();
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        if(stack.isEmpty())
            System.out.println("FRULA");
        else{
            for(int i=stack.size()-1;i>=0;i--){
                sb.append(stack.pop());
            }
        }
        System.out.println(sb);
    }
}