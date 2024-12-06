class Student {
    private:
        string name;

        vector<string> recommendedCourses;
    
    public:
        Student(Const string& name);

        string getName() const;

        void addRecommendation(const string& course);

        vector<string> getRecommendations() const;
        
}