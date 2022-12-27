using System;

public class Trie
{
    public Trie[] links = new Trie[26];
    public bool flag = false;

    public bool IsContains(char ch)
    {
        return links[ch - 'a'] != null;
    }

    public Trie GetLinkNode(char ch)
    {
        return links[ch - 'a'];
    }

    public void InsertLinkNode(char ch, Trie node)
    {
        links[ch - 'a'] = node;
    }
}

public class Algorithm
{
    public Trie root = null;

    public Algorithm()
    {
        root = new Trie();
    }
    public void InsertToTrieTree(string words)
    {
        Trie trieTree = root;

        for(int i = 0; i < words.Length; i++)
        {
            if (!trieTree.IsContains(words[i]))
            {
                trieTree.InsertLinkNode(words[i], new Trie());
            }

            trieTree = trieTree.GetLinkNode(words[i]);
        }
        trieTree.flag = true;
    }

    public bool SearchWord(string word)
    {
        Trie node = root;
        for(int i = 0; i < word.Length; i++)
        {
            if (!node.IsContains(word[i]))
            {
                return false;
            }
            node = node.GetLinkNode(word[i]);
        }
        return node.flag;
    }

    public bool StartWith(string word)
    {
        Trie node = root;
        for (int i = 0; i < word.Length; i++)
        {
            if (!node.IsContains(word[i]))
            {
                return false;
            }
            node = node.GetLinkNode(word[i]);
        }
        return true;
    }

    public static void Main(string[] args)
    {
        var algorithm = new Algorithm();
        var words = new string[]{"apples", "apps", "bps" };
        
        foreach(var word in words)
        {
            algorithm.InsertToTrieTree(word);
        }

        Console.WriteLine("Is Found apps {0}", algorithm.SearchWord("pps"));
        Console.WriteLine("Is Found apps {0}", algorithm.StartWith("r"));
    }
}