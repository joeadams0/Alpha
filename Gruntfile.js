var version = '0.0.0'


var mountFolder = function (connect, dir) {
  return connect.static(require('path').resolve(dir));
};

module.exports = function (grunt) {
	/**
	 * Edit these build settings
	 */

	// Path to emscripten em++ file
	var jsCompiler = 'em++',
		// Clang compiler
		clangCompiler = 'clang++',

		// Add what you like
		cmdLineArgs = [
			'-O2',
			'-Wno-c++11-extensions'
		],	

		args = cmdLineArgs.join(' '),

		// Get engine files to compile
		engineFiles = grunt.file.expand('Engine/**/*.cpp'),
		engineFiles = engineFiles.join(' '),

		// File to be written - will be written in gameDir/build with proper extension
		outputFile = 'output',
		outputDir = '',

		// The game or example to compile
		gameDir = grunt.option('gameDir')

		gameFiles = '',
		sourceFiles = '',
		buildDir = 'build/';

	if(gameDir){
		gameFiles = grunt.file.expand(gameDir+'**/*.cpp');
		gameFiles = gameFiles.join(' ');
		outputDir = gameDir+buildDir;
	}

	grunt.file.mkdir(gameDir+buildDir);


	sourceFiles = engineFiles + ' ' + gameFiles;


	// Load
	grunt.loadNpmTasks('grunt-contrib-connect');
	grunt.loadNpmTasks('grunt-open');
	grunt.loadNpmTasks('grunt-contrib-clean');
	grunt.loadNpmTasks('grunt-contrib-watch');
	grunt.loadNpmTasks('grunt-shell');
  	

	// Init
	grunt.initConfig({
		connect : {
			options : {
				port : 9000,
				hostname : 'localhost',
				keepalive : false
			},
			example : {
				options : {
					middleware : function(connect){
						return [
							mountFolder(connect, gameDir)
						];
					}
				}
			}
		},
		open : {
			example : {
				path : 'http://localhost:<%= connect.options.port %>/'+buildDir+outputFile+'.html'
			}
		},
		clean : {
			server : 'temp',
			example : gameDir+buildDir+'/**/*'
		},
		watch : {
			livereload : {
				options : {
					livereload : true
				},
				files : [
					'./app/**/*.js'
				]
			}
		},
		shell : {
			compileJS : {
				command : jsCompiler+' '+sourceFiles+' '+args+' -o '+outputDir+outputFile+'.js' 
			},
			compileHTML : {
				command : jsCompiler+' '+sourceFiles+' '+args+' -o '+outputDir+outputFile+'.html' 
			},
			compileEXE : {
				command : clangCompiler+' '+sourceFiles+' '+args+' -std=c++11 -stdlib=libc++  -I /usr/lib/c++/v1/ -L /usr/lib/c++/v1/ -o '+outputDir+outputFile
			}
		}
	});

	// Register tasks
	grunt.registerTask('server', [
		'clean:server',
		'connect:game',
		'open:server',
		'watch:livereload'
	]);

	grunt.registerTask('build', function(type){
		if(type == 'js'){
			grunt.task.run([
				'clean:example',
				'shell:compileJS'
			]);
		}
		else if(type == 'exe'){
			grunt.task.run([
				'clean:example',
				'shell:compileEXE'
			]);
		}
		else{
			grunt.task.run([
				'clean:example',
				'shell:compileHTML',
				'connect:example',
				'open:example',
				'watch:livereload'
			]);
		}
	});
}