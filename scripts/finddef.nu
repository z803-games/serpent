def main [definition: string] {
    print $"Found definition \"($definition)\" in:"
    ar t ($env.GBDK_HOME)/lib/gb/gb.lib | lines | where {|f| (ar p ($env.GBDK_HOME)/lib/gb/gb.lib $f | grep -qa $"($definition)" | complete).exit_code == 0}
}
