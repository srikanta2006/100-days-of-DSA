import os, glob, re

def extract_leetcode():
    res = []
    # match patterns like "Question number: 136" and "Title: Single number"
    # or "450: Delete Node in a BST"
    # or "[II] 230: Kth Smallest Element in a BST"
    # or "[III] 98 Validate Binary Search Tree"
    for file in sorted(glob.glob('DAY-*/leetcode.txt')):
        day = file.split('\\')[0].replace('/', '') if '\\' in file else file.split('/')[0]
        with open(file, 'r', encoding='utf-8') as f:
            lines = f.readlines()
        
        q_num = None
        for i, line in enumerate(lines):
            line = line.strip()
            
            # case 1: Question number: 136
            m1 = re.match(r'^Question\s+number:\s*(\d+)', line, re.I)
            if m1:
                q_num = m1.group(1)
                # Next line or two should be Title
                title = ""
                for j in range(1, 4):
                    if i+j < len(lines):
                        m_title = re.match(r'^Title:\s*(.*)', lines[i+j].strip(), re.I)
                        if m_title:
                            title = m_title.group(1)
                            break
                if title:
                    res.append((day, q_num, title))
                continue
            
            # case 2: [II] 230: Kth Smallest Element in a BST
            # or 450: Delete Node in a BST
            m2 = re.match(r'^(?:\[[IVX]+\]\s*)?(\d+)\s*[:-]?\s*(.*)', line)
            if m2 and not line.lower().startswith('question'):
                num, title = m2.group(1), m2.group(2)
                remainder = line[m2.end(1):].lstrip()
                if remainder and remainder[0] in [']', ')', '.', '>']:
                    continue
                if len(num) > 0 and len(title) > 0:
                    res.append((day, num, title))
                    
    return res

def extract_gfg():
    res = []
    for file in sorted(glob.glob('DAY-*/geeks_for_geeks.txt')):
        day = file.split('\\')[0].replace('/', '') if '\\' in file else file.split('/')[0]
        with open(file, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                m = re.match(r'^\[[IVX]+\]\s*(.*)', line)
                if m:
                    res.append((day, m.group(1)))
    return res

lc = extract_leetcode()
with open('Leetcode_Questions.txt', 'w', encoding='utf-8') as f:
    f.write("Day | Number | Title\n")
    f.write("-" * 50 + "\n")
    for day, num, title in lc:
        f.write(f"{day} | {num} | {title}\n")

gfg = extract_gfg()
with open('geeks_for_geeks.txt', 'w', encoding='utf-8') as f:
    f.write("Day | Title\n")
    f.write("-" * 50 + "\n")
    for day, title in gfg:
        f.write(f"{day} | {title}\n")

print("Done. Extracted Leetcode:", len(lc), "GFG:", len(gfg))
