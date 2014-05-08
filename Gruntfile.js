var version = '0.0.0';


var mountFolder = function (connect, dir) {
  return connect.static(require('path').resolve(dir));
};

module.exports = function (grunt) {
	/**
	 * Edit these build settings
	 */

	// Path to emscripten em++ file
	var compiler = 'em++',

		// Add what you like
		cmdLineArgs = [
			'-O0',
			'-Wno-c++11-extensions',
			'-I Engine/Include'
		],	

		args = cmdLineArgs.join(' '),

		// Get engine files to compile
		engineFiles = grunt.file.expand([
			'Engine/**/*.cpp',
			'!Engine/Include/boost/**/*.cpp'
		]),
		engineFiles = engineFiles.join(' '),

		// The game or example to compile
		gameDir = grunt.option('gameDir'),
		buildDir = 'build/',
		// File to be written - will be written in gameDir/build with proper extension
		outputFile = 'output',

		gameFiles = '',
		sourceFiles = '',
		outputDir = '';

	if(gameDir){
		gameFiles = grunt.file.expand(gameDir+'**/*.cpp');
		gameFiles = gameFiles.join(' ');
		outputDir = gameDir+buildDir;
	}
	else
		gameDir = '';

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
				command : compiler+' '+sourceFiles+' '+args+' -o '+outputDir+outputFile+'.js' 
			},
			compileHTML : {
				command : compiler+' '+sourceFiles+' '+args+' -o '+outputDir+outputFile+'.html' 
			},
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