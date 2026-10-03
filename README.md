# 📰 Fake News Detection System

A lightweight, command-line **fake news detector written in C**. It analyses a news headline or short text using a keyword-and-style heuristic and tells you whether it looks **likely real**, **suspicious**, or **likely fake**.

> ⚠️ This is a learning project. It uses simple rule-based scoring, **not** machine learning or fact-checking. Always verify news from trusted sources.

---

## ✨ Features

- Detects **sensationalist / clickbait phrases** (e.g. "shocking", "miracle", "you won't believe", "leaked")
- Detects **credibility indicators** (e.g. "according to", "study", "officials said", "published")
- Flags **excessive exclamation marks**
- Flags **excessive use of capital letters** (shouting)
- Case-insensitive keyword matching
- Safe input handling with `fgets` (no buffer overflows)
- Loop to analyse multiple headlines in one session

---

## 🧠 How It Works

The program computes a **fake score** for the input text:

| Factor | Effect on score |
| --- | --- |
| Each suspicious keyword found | **+2** |
| 2 or more exclamation marks (`!`) | **+2** |
| More than 40% of characters are capitals | **+2** |
| Each credible keyword found | **−1** |

The final score decides the verdict:

| Score | Result |
| --- | --- |
| `>= 3` | 🚨 **LIKELY FAKE NEWS** |
| `1 – 2` | ⚠️ **SUSPICIOUS** |
| `<= 0` | ✅ **LIKELY REAL NEWS** |

Each keyword counts once per input, no matter how many times it appears.

---

## 🚀 Getting Started

### Prerequisites

- A C compiler such as **GCC** or **Clang**
- Works on Linux, macOS, and Windows (MinGW / WSL)

### Compile

```bash
gcc main.c -o fake_news_detector
```

For extra warnings during development:

```bash
gcc -Wall -Wextra -std=c11 main.c -o fake_news_detector
```

### Run

```bash
./fake_news_detector
```

On Windows:

```bash
fake_news_detector.exe
```

---

## 💻 Example Usage

```text
===== FAKE NEWS DETECTION SYSTEM =====

Enter a news headline/text:
> SHOCKING!! Miracle cure for all diseases LEAKED, doctors hate this secret!

--- Analysis ---
Suspicious words found : 5
Credible words found   : 0
Exclamation marks      : 2
Fake score             : 12
Result: LIKELY FAKE NEWS - verify from trusted sources!

Check another? (y/n): y

Enter a news headline/text:
> According to a university study published today, researchers confirmed the findings.

--- Analysis ---
Suspicious words found : 0
Credible words found   : 4
Exclamation marks      : 0
Fake score             : -4
Result: LIKELY REAL NEWS.

Check another? (y/n): n
Stay informed, stay safe!
```

---

## 🗂️ Project Structure

```text
.
├── main.c   # Complete source code
└── README.md
```

---

## 🔧 Customising the Detector

Want to tune the detector? Edit the keyword arrays at the top of the source file:

```c
const char *suspicious[] = { "shocking", "miracle", "hoax", /* add more */ };
const char *credible[]   = { "according to", "study", "confirmed", /* add more */ };
```

Keywords must be **lowercase**, since the input is converted to lowercase before matching. You can also change:

- `MAX` – maximum input length (default `300` characters)
- Score weights and verdict thresholds inside the `analyse()` function

---

## ⚠️ Limitations

- Purely **keyword-based**: it cannot understand context, sarcasm, or facts
- Real news can be flagged for sensational wording, and fake news can pass if it avoids the keyword list
- English only
- Input is limited to `MAX - 1` characters

---

## 🛣️ Future Improvements

- [ ] Load keyword lists from external text files
- [ ] Read and analyse text from a file
- [ ] Weighted keywords instead of flat scoring
- [ ] Source / URL credibility checks
- [ ] Machine learning based classification

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to fork the repo and open a pull request.

---

## 👤 Author

**Inba Ilakiyan**
GitHub: [@DubberRuckky](https://github.com/DubberRuckky)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
