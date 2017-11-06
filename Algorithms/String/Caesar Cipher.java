import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        int k = in.nextInt();
        
        StringBuilder sb = new StringBuilder();
        for(Character c : s.toCharArray())
        {
            if(c <= 'z' && c >= 'a')
                sb.append((char)((c - 'a' + k) % 26 + 'a'));
            else if(c <= 'Z' && c >= 'A')
                sb.append((char)((c - 'A' + k) % 26 + 'A'));
            else
                sb.append(c);
        }
        
        System.out.println(sb.toString());
    }
}