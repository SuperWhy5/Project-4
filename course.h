class Course{
    private:
        string id;
    
    public:
        Course(const string& id);
        
        std::string getId() const;

        bool operator == (const Course& other) const;

        bool operator < (const Course& other) const;
 }