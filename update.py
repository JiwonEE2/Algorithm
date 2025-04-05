#!/usr/bin/env python

import os
from urllib import parse

HEADER = """#
# 백준, 프로그래머스 문제 풀이 목록
"""

def main():
    content = HEADER

    root_categories = ["백준", "프로그래머스"]
    for category in root_categories:
        if not os.path.exists(category):
            continue

        content += f"\n## 📚 {category}\n"

        # 난이도 폴더들 (ex. Bronze, Silver)
        for level in sorted(os.listdir(category)):
            level_path = os.path.join(category, level)
            if not os.path.isdir(level_path):
                continue

            content += f"\n### 🚀 {level}\n"
            content += "| 문제번호 | 링크 | 개념 |\n"
            content += "| -------- | ---- | ---- |\n"

            for problem_number in sorted(os.listdir(level_path)):
                problem_path = os.path.join(level_path, problem_number)
                if not os.path.isdir(problem_path):
                    continue

                problem_link = "-"
                concept_links = []

                for file in sorted(os.listdir(problem_path)):
                    if file.endswith(".md"):
                        md_path = parse.quote(os.path.join(problem_path, file))
                        if file == "README.md":
                            problem_link = f"[문제 설명]({md_path})"
                        else:
                            title = file[:-3]
                            concept_links.append(f"[{title}]({md_path})")

                # 테이블 작성
                content += "| {} | {} | {} |\n".format(
                    problem_number,
                    problem_link,
                    concept_links[0] if concept_links else "-"
                )
                for concept in concept_links[1:]:
                    content += "| | | {} |\n".format(concept)

    with open("README.md", "w", encoding="utf-8") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
