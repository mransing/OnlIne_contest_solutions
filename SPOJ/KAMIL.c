    int f(char *s)
    {switch(*s){case 84:
    case 68:
    case 70:
    case 76:
    return 2*f(s+1);
    break;
    case 0:
    return 1;
    default:
    return f(s+1);
    }}
    int main()
    {int i=0;
    for(;i<10;i++)
    {char s[21];
    scanf("%s",&s);
    printf("%d\n",f(s));
    }return 0;} 
