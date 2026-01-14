#!/usr/bin/env python3
"""
Fetch CSES problem details including title and sample test cases.
Usage: python3 fetch-cses.py <url>
"""

import sys
import re
import urllib.request
from html.parser import HTMLParser

class CSESParser(HTMLParser):
    def __init__(self):
        super().__init__()
        self.title = None
        self.in_title = False
        self.in_input_section = False
        self.in_output_section = False
        self.in_pre = False
        self.sample_input = None
        self.sample_output = None
        self.pre_content = []

    def handle_starttag(self, tag, attrs):
        if tag == 'title':
            self.in_title = True
        elif tag == 'pre':
            self.in_pre = True
            self.pre_content = []
        elif tag == 'h2':
            # Will check data to see if it's Input or Output
            pass

    def handle_endtag(self, tag):
        if tag == 'title':
            self.in_title = False
        elif tag == 'pre':
            self.in_pre = False
            content = ''.join(self.pre_content).strip()
            if content and self.in_input_section and not self.sample_input:
                self.sample_input = content
            elif content and self.in_output_section and not self.sample_output:
                self.sample_output = content
        elif tag == 'h2':
            pass

    def handle_data(self, data):
        if self.in_title and not self.title:
            # Extract title before " - CSES"
            match = re.match(r'(.+?)\s*-\s*CSES', data)
            if match:
                self.title = match.group(1).strip()
        elif data.strip() == 'Input':
            self.in_input_section = True
            self.in_output_section = False
        elif data.strip() == 'Output':
            self.in_input_section = False
            self.in_output_section = True
        elif data.strip() == 'Example':
            self.in_input_section = False
            self.in_output_section = False
        elif self.in_pre:
            self.pre_content.append(data)

def fetch_cses_problem(url):
    try:
        with urllib.request.urlopen(url) as response:
            html = response.read().decode('utf-8')

        parser = CSESParser()
        parser.feed(html)

        return {
            'title': parser.title,
            'input': parser.sample_input,
            'output': parser.sample_output
        }
    except Exception as e:
        print(f"Error fetching problem: {e}", file=sys.stderr)
        return None

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python3 fetch-cses.py <url>", file=sys.stderr)
        sys.exit(1)

    url = sys.argv[1]
    result = fetch_cses_problem(url)

    if result:
        if result['title']:
            print(f"TITLE:{result['title']}")
        if result['input']:
            print(f"INPUT:{result['input']}")
        if result['output']:
            print(f"OUTPUT:{result['output']}")

