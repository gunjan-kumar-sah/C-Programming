```markdown
# 🧠 Smart Resume Analyzer (AI-like Logic in C)

A powerful console-based Resume Analyzer built using **C language** that simulates an **AI-like ATS (Applicant Tracking System)** using weighted scoring logic. This project analyzes a resume, detects skills, and generates a smart evaluation report.

---

## 📖 About the Project

Smart Resume Analyzer is a C-based project that evaluates resumes like a basic recruitment system. It assigns different weights to different skills instead of simple equal scoring.

It behaves like a **mini ATS system** used in companies to filter candidates based on skills, projects, and experience keywords.

This project is useful for understanding:
- Real-world application of string processing
- AI-like decision making using logic
- Weighted scoring systems
- Basic ATS system design

---

## 🚀 Features

- 📄 Resume text input (single line or paragraph)
- 🧠 AI-like weighted scoring system
- 💻 Programming skills detection (C, C++, Python, Java)
- 🌐 Web development skills detection (HTML, CSS, JavaScript)
- 🤝 Soft skills evaluation (Communication, Teamwork, Leadership)
- 📊 Smart score generation (0–100)
- 💡 AI-based verdict system
- 📈 Improvement suggestions

---

## 🧠 AI Logic / Scoring System

This project uses weighted scoring instead of simple +10 logic:

### 💻 Programming Skills
- Python → +15
- Java → +15
- C → +10
- C++ → +10

### 🌐 Web Skills
- HTML → +5
- CSS → +5
- JavaScript → +10

### 🤝 Soft Skills
- Communication → +10
- Teamwork → +10
- Leadership → +10

### 🎁 Bonus Skills
- Projects → +10
- Internship → +10

📌 Maximum Score = 100

---

## ⚙️ Working Flow

1. User enters resume text
2. Text is converted to lowercase
3. System scans keywords using string matching
4. Each skill adds different weight
5. Final score is calculated
6. AI-style result and suggestions are displayed

---

## 📊 Output Example

```

===== SMART RESUME ANALYZER (AI LOGIC) =====

Enter your resume text:
I know Python Java HTML CSS communication teamwork projects internship

===== ANALYSIS RESULT =====
Resume Score: 85/100
Strength: Strong Resume 💪
AI Verdict: Highly Recommended Candidate ⭐

===== IMPROVEMENT SUGGESTIONS =====

* Good profile! Focus on advanced projects
* Learn system design concepts
* Add real-world internship experience

```

---

## 🧾 Result Classification

- 75–100 → Strong Resume 💪 (Highly Recommended ⭐)
- 45–74 → Medium Resume 👍 (Average Candidate ⚠️)
- Below 45 → Weak Resume ❌ (Needs Improvement 📉)

---

## 🧠 Concepts Used

- String handling in C (strstr, tolower)
- Conditional logic
- Weighted scoring system
- AI-like decision making simulation
- Algorithmic thinking
- Basic ATS (Applicant Tracking System) design

---

## 🛠️ Technologies Used

- C Language
- GCC Compiler
- Standard String Library
- Console-based UI

---

## 🎯 Learning Outcomes

After building this project, you will understand:

- How ATS systems work in real companies
- How AI-like logic can be built using simple C code
- Weighted scoring system design
- Real-world string processing
- Decision-making algorithms
- Resume evaluation system design

---

## 🔮 Future Improvements

- 📂 File-based resume upload (TXT/PDF parsing)
- 🤖 Machine learning integration (Python backend)
- 🌐 Web-based ATS system
- 📊 Graph-based skill ranking system
- 🧠 Advanced AI resume ranking engine
- 📈 Dashboard UI for analytics

---

## 👨‍💻 Author

**Gunjan Kumar Sah**  
🎓 B.Tech Computer Science Student  
💻 Passionate about C/C++, Data Structures, AI-like systems & Software Development

---

## ⭐ Support

If you like this project, please give it a ⭐ on GitHub.  
It helps in motivation and learning journey.

---

> 🚀 “This is not just a project, it's a mini AI system built using pure logic in C.”
```

---
