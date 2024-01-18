function [taskInfo, numtask, isDeploymentDiagram]=extmode_task_info()
    isDeploymentDiagram = 0;
                    taskInfo(1).samplePeriod = 0.0001;
            taskInfo(1).sampleOffset = 0.0;

                taskInfo(1).taskPrio = 40;

                taskInfo(1).taskName = 'BaseRate';
            taskInfo(1).entryPoints = {};
            taskInfo(1).nonFcnCallPartitionName = 'D1';

            taskInfo(2).samplePeriod = 0.01;
            taskInfo(2).sampleOffset = 0.0;

                taskInfo(2).taskPrio = 41;

                taskInfo(2).taskName = ['SubRate' '1'];
            taskInfo(2).entryPoints = {};
            taskInfo(2).nonFcnCallPartitionName = 'D2';

            taskInfo(3).samplePeriod = 0.1;
            taskInfo(3).sampleOffset = 0.0;

                taskInfo(3).taskPrio = 42;

                taskInfo(3).taskName = ['SubRate' '2'];
            taskInfo(3).entryPoints = {};
            taskInfo(3).nonFcnCallPartitionName = 'D3';




    numtask = 3;
    for i = 1:numtask
    if ( 0 == isnumeric(taskInfo(i).samplePeriod) )
    taskInfo(i).samplePeriod = evalin('base', 'str2double(taskInfo(i).samplePeriod)');
    end
    if ( isempty(taskInfo(i).taskName) )
    taskInfo(i).taskName = ['AutoGen' i ];
    end
    end

end 
