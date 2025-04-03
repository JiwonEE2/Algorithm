#!/usr/bin/env python

import os
from urllib import parse

HEADER = """#
# 백준, 프로그래머스 문제 풀이 목록
"""

def main():
    content = HEADER
    directories = []
    problem_data = {}  # {카테고리: {문제번호: {링크, 개념}}}

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)  # Bronze, Silver 등
        directory = os.path.basename(os.path.dirname(root))  # 백준, 프로그래머스 등

        if directory == '.':
            continue
        if directory not in directories:
            content += "## 📚 {}\n".format(directory)
            directories.append(directory)

        # 카테고리별로 데이터 구조 생성
        if category not in problem_data:
            problem_data[category] = {}

        for file in sorted(files):
            if not file.endswith(".md"):
                continue

            md_path = parse.quote(os.path.join(root, file))
            problem_number = os.path.basename(root)  # 문제번호

            if problem_number.isdigit():  # 숫자인 경우만 문제번호로 인정
                if problem_number not in problem_data[category]:
                    problem_data[category][problem_number] = {
                        "link": "-",
                        "concepts": []
                    }

                if file == "README.md":
                    problem_data[category][problem_number]["link"] = "[문제 설명]({})".format(md_path)
                else:
                    title = file[:-3]  # 확장자 제거
                    problem_data[category][problem_number]["concepts"].append("[{}]({})".format(title, md_path))

    # 카테고리별 테이블 작성
    for category, problems in problem_data.items():
        content += f"\n### 🚀 {category}\n"
        content += "| 문제번호 | 링크 | 개념 |\n"
        content += "| ----- | ----- | ----- |\n"

        for problem_number, data in sorted(problems.items()):
            problem_link = data["link"]
            concept_links = data["concepts"]

            # 첫 번째 행
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
