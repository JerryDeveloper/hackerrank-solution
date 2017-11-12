import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static int matchPattern(Character x, Character y, String s)
    {
        int i = 0;
        Character prevChar = x;   // randomly assigned
        int counter = 0;
        while(i < s.length())
        {
            if(x != s.charAt(i) && y != s.charAt(i))
                ++i;
            else
            {
                prevChar = s.charAt(i);
                ++counter;
                break;
            }
        }
            
        if(i == s.length())
            return 0;
        
        for(i = i + 1; i < s.length(); ++i)
        {
            if(x != s.charAt(i) && y != s.charAt(i))
                continue;
            if(s.charAt(i) == prevChar)
                return 0;
            
            prevChar = s.charAt(i);
            ++counter;
        }
        
        return counter;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int len = in.nextInt();
        String s = in.next();
        
        // count occurence of all characters. the counts of x and y have difference of 1
        // find all candidate pairs and check the location
        Map<Character, Integer> counter = new HashMap<>();
        for(int i = 0; i < s.length(); ++i)
        {
            Character c = s.charAt(i);
            if(counter.containsKey(c))
                counter.put(c, counter.get(c) + 1);
            else
                counter.put(c, 1);
        }
        
        // sort the map by value
        Set<Map.Entry<Character, Integer>> entries = counter.entrySet();
        List<Map.Entry<Character, Integer>> list = new ArrayList<Map.Entry<Character, Integer>>(entries);
        Collections.sort(list, (Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) -> (o2.getValue()).compareTo(o1.getValue()));
        
        
        // traverse through possible char pairs
        int max_len = 0;
        boolean found = false;
        for(int largePtr = 0; largePtr < list.size() - 1; ++largePtr)
        {
            for(int smallPtr = largePtr + 1; smallPtr < list.size(); ++smallPtr)
            {
                int diff = list.get(largePtr).getValue() - list.get(smallPtr).getValue();
                if(diff > 1)
                    break;
                
                int sum = list.get(largePtr).getValue() + list.get(smallPtr).getValue();
                if(sum < max_len)
                    break;
                
                int tmp = matchPattern(list.get(smallPtr).getKey(), list.get(largePtr).getKey(), s);
                if(tmp != 0 && max_len < tmp)
                    max_len = tmp;
            }
        }
        
        System.out.println(max_len);
    }
}
