//rdmd dprocess.d
//dmd dprocess.d -ofqt/resources/dprocess

import std.stdio, std.string, std.file, std.json, std.algorithm, std.conv, std.regex, std.exception;
import std.c.process;
// import d2sqlite3;
// 
// pragma(lib, "sqlite3");

/++ CTFE embedding resources +/
//static immutable string sqlt_memory = ":memory:";
//static immutable string pentview_sql = import("pentviews.sql");

auto exit_status = 0;

int main(string[] args)
{
    import std.getopt;
    
    auto console = true;
    
    /++ arg handling +/
    auto help = false;
    auto ver = false;

    try
    {
        args.getopt("h|help", &help, "v|version", &ver);
    }
    catch (Exception e)
    {
        writeln("#### Unrecognized option ####");
        displayHelp();
        exit_status = 1;
    }

    if (ver)
    {
        displayVersion;
        exit(0);
    }

    if (help)
    {
        displayHelp();
        exit(0);
    }


    displayVersion;
    while (console)
    {
        auto input = chomp(readln());
        if (input == "q")
        {
            console = false;
        }
        else
        {
            try
            {
                auto output = processRequest(input);
               stdout.write(output);
         //      writeln(output, "writeln out");
//                   stderr.write(output);
            }
            catch (Exception e)
            {
                displayExceptions(e);
            }
        }
    }
    return exit_status;
}

auto processRequest(string input)
{
//     switch (input)
//     {
//         default:
//         {
//             return input;
//         }
//         case: "test"
//         {
            JSONValue jv = [["11","12"],["13","21"],["22","23"]];
            return jv.toString;
//         }
//     }
}

void displayExceptions(Exception e)
{
    writeln("Primary Exception: ", typeid(e), " --> ", e);
    while (e.next)
    {
        writeln("Collateral Exception: ", typeid(e), " --> ", e);
    }
}

void displayVersion()
{
    writeln("chronicled version : " ~ version_string);
}
    
void displayHelp()
{
    displayVersion;
    writeln(
        "\nusage example:\n\\dprocess\n");
}

string getUtf8String(ubyte[] rawdata)
{
    string utf8string;
    import std.utf, std.encoding;

    try
    {
        validate!string(cast(string) rawdata);
        utf8string = cast(string) rawdata;
    }
    catch (UTFException t)
    {
        // not utf-8, try latin1
        writeln(
            "WARNING: invalid utf8 characters encountered - assuming Latin1 encoding for conversion to utf8");
        transcode(cast(Latin1String) rawdata, utf8string);
    }
    return utf8string;
}

static immutable string version_string = "0.0.1";
