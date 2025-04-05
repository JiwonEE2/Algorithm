#!/usr/bin/env python

import os
from urllib import parse

HEADER = """#
# 백준, 프로그래머스 문제 풀이 목록
"""

def main():
    content = HEADER
    directories = []
    problem_data = {}  # 문제번호별 데이터 저장

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        if category == 'images':
            continue

        directory = os.path.basename(os.path.dirname(root))
        if directory == '.':
            continue

        if directory not in directories:
            if directory in ["백준", "프로그래머스"]:
                content += "## 📚 {}\n".format(directory)
            elif directory in ["Bronze", "Silver", "Gold"]:
                content += "### 🚀 {}\n".format(directory)
                content += "| 문제번호 | 링크 | 개념 |\n"
                content += "| ----- | ----- | ----- |\n"
            directories.append(directory)

        problem_number = category  # 문제번호
        problem_link = "-"
        concept_links = []  # 개념 파일 리스트

        for file in sorted(files):  
            if file.endswith(".md"):  
                md_path = parse.quote(os.path.join(root, file))  

                if file == "README.md":  
                    problem_link = "[문제 설명]({})".format(md_path)
                else:
                    title = file[:-3]  # ".md" 확장자 제거 (파일명이 개념 제목)
                    concept_links.append("[{}]({})".format(title, md_path))

        # 문제번호별 데이터 저장
        if problem_number not in problem_data:
            problem_data[problem_number] = {"link": problem_link, "concepts": concept_links}
        else:
            problem_data[problem_number]["concepts"].extend(concept_links)

    # 테이블 작성
    for problem_number, data in problem_data.items():
        problem_link = data["link"]
        concept_links = data["concepts"]

        # 첫 번째 행 작성
        content += "| {} | {} | {} |\n".format(
            problem_number, 
            problem_link, 
            concept_links[0] if concept_links else "-"
        )

        # 개념이 여러 개라면 추가 행 작성
        for concept in concept_links[1:]:
            content += "| | | {} |\n".format(concept)

    with open("README.md", "w") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
