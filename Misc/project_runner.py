from subprocess import run
msbuild_dir = 'C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\MSBuild\\15.0\\Bin'
msbuild = 'msbuild.exe'
target_solution = 'D:\\OneDrive\\pp\\infa\\semestrVI\\PR\\Laby\\OpenMP\\OMPMul\\OMPMul.sln'

def runner():
    args = []
    args.append('{}\\{}'.format(msbuild_dir, msbuild))
    args.append(target_solution)
    run(args)


if __name__=='__main__':
    runner()
