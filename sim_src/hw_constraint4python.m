function cond = hw_constraint4python(X, filename)
    % wrapper MATLAB function called by Python to evaluate a hardware 
    % constraint classifier
    %   X is a Python dictionary of parameters that will be passed as inputs 
    %       into the classfier
    %   filename is string detailing the path of where the classifier object is 
    %       saved; should be a *.mat file with the classifier saved as 
    %       'cas_classfier', which should be a CasADi function-based 
    %       implementation of the hardware classifier
    % the output of this function is whether or not the parameters will result 
    % in a feasible hardware implementation as determined by the classifier

    X = struct(X);
    filename = char(filename);

    fnames = fieldnames(X);
    for i = 1:length(fnames)
        switch fnames{i}
            case 'H'
                Hopt = double(X.(fnames{i}));
            case 'fxp_word_length'
                fxp_word_length = double(X.(fnames{i}));
        end
    end

    if isempty(filename)
        error('No filename provided for the classifier!')
    end

    my_classifier = load(filename, 'cas_classifier').cas_classifier;
    in = [Hopt fxp_word_length]';
    out = full(my_classifier(in));
    [~, idx] = max(out);
    cond = logical(idx'-1);
end