HuffmanEncoding(text):
    1. Calculate frequency of each character in text
    2. Insert all characters into a Min-Heap (Priority Queue)
    3. While more than one node in heap:
        a. Extract two nodes with lowest frequency
        b. Create a new node with sum of frequencies
        c. Set extracted nodes as left and right children
        d. Insert new node back into heap
    4. Extract root node (Huffman Tree is ready)
    5. Traverse Huffman Tree to generate binary codes
    6. Replace characters in text with Huffman codes (Encoding)
    7. Decode back using Huffman Tree (Decoding)
