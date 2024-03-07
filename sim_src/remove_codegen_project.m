function remove_codegen_project()
  % small helper function to remove the codegen files to avoid the overwrite
  % prompt; file paths are currently hard-coded
project_path = './hdlcoder_fullDNN/codegen/plasma_nn_wrapper';
rmdir(project_path, 's')
end
