class cSeverity
{
public:
    enum teSeverity
    {
        MIN = 0,
        NONE,
        ERROR,
        WARNING,
        INFO,
        DEBUG,
        MAX
    };

    static const char *toStr( teSeverity p_enSev ) {
        switch( p_enSev ) {
            case NONE:    return "NONE";    break;
            case ERROR:   return "ERROR";   break;
            case WARNING: return "WARNING"; break;
            case INFO:    return "INFO";    break;
            case DEBUG:   return "DEBUG";   break;
            default:      return "INVALID";
        }
    }
};


