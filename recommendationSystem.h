class RecommendationSystem{
    private:
        map<string, Student> students;

        set<string> course;

    public:
        void loadData(const string& filename);

        vector<string> generateRecommendationsForStudent(const string& studentName) const;

        void outputRecommendations(ostream& out) const;

        int getTotalStudents() const;

        int getTotalCourses() const;

        int getTotalRecommendations() const;
        
}