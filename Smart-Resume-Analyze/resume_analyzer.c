#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Convert string to lowercase
void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// Check keyword in resume
int contains(char *resume, char *keyword)
{
    if (strstr(resume, keyword) != NULL)
        return 1;
    return 0;
}

int main()
{
    char resume[1500];
    int score = 0;

    printf("===== SMART RESUME ANALYZER (AI LOGIC) =====\n");

    printf("\nEnter your resume text:\n");
    fgets(resume, sizeof(resume), stdin);

    toLowerCase(resume);

    // -------------------------------
    // Programming Skills (High Weight)
    // -------------------------------
    if (contains(resume, "c")) score += 10;
    if (contains(resume, "cpp")) score += 10;
    if (contains(resume, "python")) score += 15;
    if (contains(resume, "java")) score += 15;

    // -------------------------------
    // Web Development Skills
    // -------------------------------
    if (contains(resume, "html")) score += 5;
    if (contains(resume, "css")) score += 5;
    if (contains(resume, "javascript")) score += 10;

    // -------------------------------
    // Soft Skills
    // -------------------------------
    if (contains(resume, "communication")) score += 10;
    if (contains(resume, "teamwork")) score += 10;
    if (contains(resume, "leadership")) score += 10;

    // -------------------------------
    // Extra AI-like bonus logic
    // -------------------------------
    if (contains(resume, "project")) score += 10;
    if (contains(resume, "internship")) score += 10;

    // Max cap
    if (score > 100)
        score = 100;

    printf("\n===== ANALYSIS RESULT =====\n");
    printf("Resume Score: %d/100\n", score);

    // Classification
    if (score >= 75)
    {
        printf("Strength: Strong Resume 💪\n");
        printf("AI Verdict: Highly Recommended Candidate ⭐\n");
    }
    else if (score >= 45)
    {
        printf("Strength: Medium Resume 👍\n");
        printf("AI Verdict: Average Candidate ⚠️\n");
    }
    else
    {
        printf("Strength: Weak Resume ❌\n");
        printf("AI Verdict: Needs Improvement 📉\n");
    }

    // Suggestions
    printf("\n===== IMPROVEMENT SUGGESTIONS =====\n");

    if (score < 75)
    {
        printf("- Add more technical skills (Python/Java)\n");
        printf("- Work on real-world projects\n");
        printf("- Include internship experience\n");
        printf("- Improve communication skills\n");
    }
    else
    {
        printf("- Good profile! Focus on advanced projects\n");
        printf("- Add system design knowledge\n");
    }

    return 0;
}